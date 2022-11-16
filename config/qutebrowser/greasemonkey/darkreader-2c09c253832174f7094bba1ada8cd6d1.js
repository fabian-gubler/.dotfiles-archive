// ==UserScript==
// @name          Dark Reader (file://*)
// @run-at        document-end
// @grant         none
// @include       file://*
// @require       https://cdn.jsdelivr.net/npm/darkreader/darkreader.min.js
// ==/UserScript==
// original url: file:///tmp/neomutt-fedora-1000-264960-8473843463210814418.html
DarkReader.setFetchMethod(window.fetch);DarkReader.enable({
	brightness: 90,
	contrast: 90,
	sepia: 50
});