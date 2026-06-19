-- Run once on existing databases before deploying the character-aware garage scripts.
-- Empty character_uid values are treated as legacy vehicles and are claimed by the
-- first character who retrieves or stores them in the matching role garage.

ALTER TABLE `vehicles`
    ADD COLUMN `character_uid` VARCHAR(96) NOT NULL DEFAULT '' AFTER `pid`,
    ADD INDEX `index_character_garage` (`pid`,`character_uid`,`side`,`type`,`alive`,`active`);
