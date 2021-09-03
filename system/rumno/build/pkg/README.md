# Notes on how to handle PKGBUILDs

## Update the version of the package
1. Update the md5sum
`makepkg -g -f -p PKGBUILD`

2. Update all references of the version number (vX.Y) in the PKGBUILD

3. Push a new version online
```
$ git tag -a vX.Y -m "bake default images into binary"
$ git push origin vX.Y
```

4. Update aur repo
