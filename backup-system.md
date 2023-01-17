# Backup Strategy
## TODO
- Purchase external HDD
- Setup Borg Backup script (e.g. systemd timer)

## Important Files (Cloud)
| Data type                         | Storage                   |
| ---                               | ---                       |
| Media, Personal, Application Data | Host + Nextcloud          |
| Code Repositories & Configuration | Host + Github             |
| VM                                | Host + Nextcloud (Latest) |

## Regular Files 
| Data type     | Storage                          |
| ---           | ---                              |
| OS Recovery   | NixOS (generations)              |
| Data Recovery | Borg Backup (data deduplication) |


[Borg - Arch Wiki](https://wiki.archlinux.org/title/Borg_backup)
1. `init` to initialize repository
2. `create` to backup using custom params (pref. automated)
3. `prune` to remove old archives (pref. automated)
Restore: `extract` or `mount`
