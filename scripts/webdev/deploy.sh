echo
echo "Remove preexisting repository"
echo
rm -rf /data/deploy/

echo
echo "Clone Repo into /data/deploy"
echo
git clone git@github.com:universitychat/website.git "/data/deploy"
cd /data/deploy/
npm install

echo
echo "Deploy to github.io"
echo

ng deploy --base-href=/website/
