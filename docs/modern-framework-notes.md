# Modern Framework Extension Notes

## Permission Source Contract

Discord bots and admin panels can grant permissions without changing the live
job by writing SQF-style array text to `steam_whitelist.permissions` or
`discord_permissions.permissions`.

Example values:

```sql
INSERT INTO steam_whitelist (pid, faction, level, permissions, notes)
VALUES ('76561198000000000', 'police', 3, '["police.access","police.cuff","police.ticket"]', 'Initial whitelist');

INSERT INTO discord_permissions (pid, discord_id, roles, permissions)
VALUES ('76561198000000000', '123456789012345678', '["LEO","Staff"]', '["police.access","staff.access"]');
```

The client merges those grants into `life_permissions`. The signed-on job stays
in `life_active_job`, so a character can be on duty for one job while still
holding permissions for another approved role.

## Character IDs

Character slots are currently stored locally by Steam ID plus Arma profile name:

```sqf
life_characters_<steamId>_<profileName>
```

The SQL `characters` table mirrors the same model and is ready for server-side
persistence when the character save/load endpoints are promoted from local
profile storage.

## Legal HUD Data

The HUD and ID card read:

- `life_pending_citations`
- `life_pending_warrants`

Those arrays are filled by `DB_fnc_fetchFrameworkData` from the `citations` and
`warrants` tables.
