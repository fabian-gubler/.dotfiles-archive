// TODO: Some/most of this is already present in https://github.com/getferdi/ferdi/blob/develop/src/webview/screenshare.js#L5

const _path = _interopRequireDefault(require('path'));

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

window.navigator.mediaDevices.getDisplayMedia = () => {
  return new Promise(async (resolve, reject) => {
    try {
      const sources = await Ferdi.desktopCapturer.getSources({ types: ['screen', 'window'] });

      const selectionElem = document.createElement('div');
      selectionElem.classList = 'desktop-capturer-selection';
      selectionElem.innerHTML = `
        <div class="desktop-capturer-selection__scroller">
          <ul class="desktop-capturer-selection__list">
            ${sources.map(({ id, name, thumbnail, display_id, appIcon }) => `
              <li class="desktop-capturer-selection__item">
                <button class="desktop-capturer-selection__btn" data-id="${id}" title="${name}">
                  <img class="desktop-capturer-selection__thumbnail" src="${thumbnail.toDataURL()}" />
                  <span class="desktop-capturer-selection__name">${name}</span>
                </button>
              </li>
            `).join('')}
          </ul>
        </div>
      `;
      document.body.appendChild(selectionElem);

      document.querySelectorAll('.desktop-capturer-selection__btn')
        .forEach(button => {
          button.addEventListener('click', async () => {
            try {
              const id = button.getAttribute('data-id');
              const source = sources.find(source => source.id === id);
              if (!source) {
                throw new Error(`Source with id ${id} does not exist`);
              }

              const stream = await window.navigator.mediaDevices.getUserMedia({
                audio: false,
                video: {
                  mandatory: {
                    chromeMediaSource: 'desktop',
                    chromeMediaSourceId: source.id
                  }
                }
              });
              resolve(stream);

              selectionElem.remove();
            } catch (err) {
              reject(err);
            }
          });
        });
    } catch (err) {
      reject(err);
    }
  })
}

module.exports = (Ferdi, settings) => {
  const getMessages = function getMessages() {
    let count = 0;
    const container = document.querySelector('[role="tablist"] > [title="Chats"] > div');

    if (container) {
      const children = container.children;

      if (children.length === 3) {
        const elementContainer = children[children.length - 1];

        if (elementContainer) {
          const element = elementContainer.querySelector('[data-text-as-pseudo-element]');
          if (element && element.dataset) {
            count = Ferdi.safeParseInt(element.dataset.textAsPseudoElement);
          }
        }
      }
    }

    Ferdi.setBadge(count);
  };

  Ferdi.loop(getMessages);

  Ferdi.injectCSS(_path.default.join(__dirname, 'service.css'));

  document.addEventListener('click', event => {
    const link = event.target.closest('a[href^="http"]');
    const button = event.target.closest('button[title^="http"]');

    if (link || button) {
      const url = link ? link.getAttribute('href') : button.getAttribute('title');
      event.preventDefault();
      event.stopPropagation();

      if (url.includes('views/imgpsh_fullsize_anim')) {
        let win = new Ferdi.BrowserWindow({
          width: 800,
          height: window.innerHeight,
          minWidth: 600,
          webPreferences: {
            partition: `persist:service-${settings.id}`
          }
        });
        win.loadURL(url);
        win.on('closed', () => {
          win = null;
        });
      } else {
        window.open(url);
      }
    }
  }, true);
};
