# Modern Framework Extension Notes

## Permission Source Contract

Discord bots and admin panels can grant permissions without changing the live
job by writing SQF-style array text to `steam_whitelist.permissions` or
`discord_permissions.permissions`.

Built-in Community Manager grants are configured in `Life_CommunityOwnerGrant` inside
`Kings_Life.Anzusmap\modules\Jobs\Config.hpp`. Steam64 `76561198810688206` is registered there as
`Community Manager`. That grant is not tied to KCSO rank or department access;
law enforcement roles come from `leo_memberships`, where George Dunn is seeded
as KCSO Commissioner.

Example values:

```sql
INSERT INTO steam_whitelist (pid, faction, level, permissions, notes)
VALUES ('76561198000000000', 'kcso', 3, '["leo.access","leo.department.kcso","police.access"]', 'Initial KCSO whitelist');

INSERT INTO discord_permissions (pid, discord_id, roles, permissions)
VALUES ('76561198000000000', '123456789012345678', '["LEO","Staff"]', '["leo.access","staff.access"]');
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
