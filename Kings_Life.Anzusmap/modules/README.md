# Mission Modules

Custom mission work lives here by feature. Keep legacy Altis Life framework files in `core` unless the framework already has an extension point that should be used.

Each module can contain:

- `fn_*.sqf` client functions registered in `Functions.hpp` under a `Module_*` CfgFunctions class.
- `Config.hpp` files included from `config\Config_Master.hpp` or `description.ext`.
- Dialog `.hpp` files included from `dialog\MasterHandler.hpp`.
- `configuration.sqf` for module-owned missionNamespace defaults included by `core\configuration.sqf`.

Prefer extending existing framework functions, shops, actions, or handlers before adding a new duplicate function. If a feature has to hook an existing framework file, keep that hook small and send the real behavior to this module folder.
