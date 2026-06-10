SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";
--
-- Compatible with newer MySQL versions. (After MySQL-5.5)
-- This SQL uses utf8mb4 and has CURRENT_TIMESTAMP function.
--


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Creates database `altislife` unless it already exists and uses `altislife`
-- Default Schema
--
CREATE DATABASE IF NOT EXISTS `altislife` DEFAULT CHARACTER SET utf8mb4;
USE `altislife`;

--
-- Drop procedures to ensure no conflicts
--
DROP PROCEDURE IF EXISTS `resetLifeVehicles`;
DROP PROCEDURE IF EXISTS `deleteDeadVehicles`;
DROP PROCEDURE IF EXISTS `deleteOldHouses`;
DROP PROCEDURE IF EXISTS `deleteOldGangs`;
DROP PROCEDURE IF EXISTS `deleteOldContainers`;
DROP PROCEDURE IF EXISTS `deleteOldWanted`;

DELIMITER $$
--
-- Procedures
-- CURRENT_USER function returns the name of the current user in the SQL Server database.
--

CREATE DEFINER=CURRENT_USER PROCEDURE `resetLifeVehicles`()
BEGIN
  UPDATE `vehicles` SET `active`= 0;
END$$

CREATE DEFINER=CURRENT_USER PROCEDURE `deleteDeadVehicles`()
BEGIN
  DELETE FROM `vehicles` WHERE `alive` = 0;
END$$

CREATE DEFINER=CURRENT_USER PROCEDURE `deleteOldHouses`()
BEGIN
  DELETE FROM `houses` WHERE `owned` = 0;
END$$

CREATE DEFINER=CURRENT_USER PROCEDURE `deleteOldGangs`()
BEGIN
  DELETE FROM `gangs` WHERE `active` = 0;
END$$

CREATE DEFINER=CURRENT_USER PROCEDURE `deleteOldContainers`()
BEGIN
  DELETE FROM `containers` WHERE `owned` = 0;
END$$

CREATE DEFINER=CURRENT_USER PROCEDURE `deleteOldWanted`()
BEGIN
  DELETE FROM `wanted` WHERE `active` = 0;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `players`
--

CREATE TABLE IF NOT EXISTS `players` (
    `uid`          INT NOT NULL AUTO_INCREMENT,
    `pid`          VARCHAR(17) NOT NULL,
    `name`         VARCHAR(32) NOT NULL,
    `aliases`      TEXT NOT NULL,
    `cash`         INT NOT NULL DEFAULT 0,
    `bankacc`      INT NOT NULL DEFAULT 0,
    `coplevel`     ENUM('0','1','2','3','4','5','6','7') NOT NULL DEFAULT '0',
    `mediclevel`   ENUM('0','1','2','3','4','5') NOT NULL DEFAULT '0',
    `civ_licenses` TEXT NOT NULL,
    `cop_licenses` TEXT NOT NULL,
    `med_licenses` TEXT NOT NULL,
    `civ_gear`     TEXT NOT NULL,
    `cop_gear`     TEXT NOT NULL,
    `med_gear`     TEXT NOT NULL,
    `civ_stats`    VARCHAR(25) NOT NULL DEFAULT '"[100,100,0]"',
    `cop_stats`    VARCHAR(25) NOT NULL DEFAULT '"[100,100,0]"',
    `med_stats`    VARCHAR(25) NOT NULL DEFAULT '"[100,100,0]"',
    `arrested`     TINYINT NOT NULL DEFAULT 0,
    `adminlevel`   ENUM('0','1','2','3','4','5')  NOT NULL DEFAULT '0',
    `donorlevel`   ENUM('0','1','2','3','4','5')  NOT NULL DEFAULT '0',
    `blacklist`    TINYINT NOT NULL DEFAULT 0,
    `civ_alive`    TINYINT NOT NULL DEFAULT 0,
    `civ_position` VARCHAR(32) NOT NULL DEFAULT '"[]"',
    `playtime`     VARCHAR(32) NOT NULL DEFAULT '"[0,0,0]"',
    `insert_time`  TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `last_seen`    TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    
    PRIMARY KEY (`pid`),
    UNIQUE KEY `unique_uid` (`uid`),
    INDEX `index_name` (`name`),
    INDEX `index_blacklist` (`blacklist`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `characters`
-- Framework identity records. Existing `players` rows remain account-level.
--

CREATE TABLE IF NOT EXISTS `characters` (
    `id`               INT NOT NULL AUTO_INCREMENT,
    `pid`              VARCHAR(17) NOT NULL,
    `profile_name`     VARCHAR(64) NOT NULL,
    `slot`             TINYINT NOT NULL,
    `character_uid`    VARCHAR(96) NOT NULL,
    `display_name`     VARCHAR(64) NOT NULL,
    `date_of_birth`    VARCHAR(16) NOT NULL,
    `political_status` VARCHAR(64) NOT NULL DEFAULT 'Resident',
    `background`       TEXT NOT NULL,
    `face`             VARCHAR(64) NOT NULL DEFAULT 'WhiteHead_01',
    `uniform`          VARCHAR(64) NOT NULL DEFAULT 'U_C_Poloshirt_blue',
    `licenses`         TEXT NOT NULL,
    `records`          TEXT NOT NULL,
    `tickets`          TEXT NOT NULL,
    `statuses`         TEXT NOT NULL,
    `insert_time`      TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `last_seen`        TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_character_uid` (`character_uid`),
    UNIQUE KEY `unique_character_slot` (`pid`,`profile_name`,`slot`),
    INDEX `index_character_name` (`display_name`),
    CONSTRAINT `FK_players_characters` FOREIGN KEY `fkIdx_players_characters` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Standalone job and permission grants.
--

CREATE TABLE IF NOT EXISTS `character_jobs` (
    `id`            INT NOT NULL AUTO_INCREMENT,
    `pid`           VARCHAR(17) NOT NULL,
    `character_uid` VARCHAR(96) NOT NULL,
    `job_key`       VARCHAR(64) NOT NULL,
    `rank`          INT NOT NULL DEFAULT 0,
    `active`        TINYINT NOT NULL DEFAULT 1,
    `source`        VARCHAR(32) NOT NULL DEFAULT 'server',
    `insert_time`   TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_character_job` (`character_uid`,`job_key`),
    INDEX `index_job_key` (`job_key`),
    CONSTRAINT `FK_characters_jobs` FOREIGN KEY `fkIdx_characters_jobs` (`character_uid`)
      REFERENCES `characters` (`character_uid`)
      ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT `FK_players_character_jobs` FOREIGN KEY `fkIdx_players_character_jobs` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `steam_whitelist` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `pid`         VARCHAR(17) NOT NULL,
    `faction`     VARCHAR(64) NOT NULL,
    `level`       INT NOT NULL DEFAULT 0,
    `permissions` TEXT NOT NULL,
    `active`      TINYINT NOT NULL DEFAULT 1,
    `notes`       TEXT NOT NULL,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_pid_faction` (`pid`,`faction`),
    CONSTRAINT `FK_players_steam_whitelist` FOREIGN KEY `fkIdx_players_steam_whitelist` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `discord_permissions` (
    `id`           INT NOT NULL AUTO_INCREMENT,
    `pid`          VARCHAR(17) NOT NULL,
    `discord_id`   VARCHAR(32) NOT NULL,
    `roles`        TEXT NOT NULL,
    `permissions`  TEXT NOT NULL,
    `active`       TINYINT NOT NULL DEFAULT 1,
    `last_sync`    TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_discord_pid` (`pid`,`discord_id`),
    INDEX `index_discord_id` (`discord_id`),
    CONSTRAINT `FK_players_discord_permissions` FOREIGN KEY `fkIdx_players_discord_permissions` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Named Law Enforcement memberships, command terminal data, and academy tools.
-- These tables replace numeric cop rank as the source of truth for LEO roles.
--

CREATE TABLE IF NOT EXISTS `leo_memberships` (
    `id`                  INT NOT NULL AUTO_INCREMENT,
    `pid`                 VARCHAR(17) NOT NULL,
    `character_uid`       VARCHAR(96) NOT NULL,
    `department_key`      VARCHAR(64) NOT NULL,
    `rank_key`            VARCHAR(64) NOT NULL,
    `primary_subdivision` VARCHAR(64) NOT NULL DEFAULT 'patrol',
    `subdivisions`        TEXT NOT NULL,
    `role_permissions`    TEXT NOT NULL,
    `status`              ENUM('active','fired','suspended') NOT NULL DEFAULT 'active',
    `hired_by_pid`        VARCHAR(17) NOT NULL,
    `updated_by_pid`      VARCHAR(17) NOT NULL,
    `notes`               TEXT NOT NULL,
    `insert_time`         TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at`          TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_leo_membership` (`pid`,`character_uid`,`department_key`),
    INDEX `index_leo_department` (`department_key`,`status`),
    INDEX `index_leo_pid_status` (`pid`,`status`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `leo_training_documents` (
    `id`             INT NOT NULL AUTO_INCREMENT,
    `department_key` VARCHAR(64) NOT NULL DEFAULT 'tcsd',
    `title`          VARCHAR(96) NOT NULL,
    `body`           TEXT NOT NULL,
    `created_by_pid` VARCHAR(17) NOT NULL,
    `active`         TINYINT NOT NULL DEFAULT 1,
    `insert_time`    TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at`     TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    INDEX `index_training_docs` (`department_key`,`active`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `leo_training_roster` (
    `id`                    INT NOT NULL AUTO_INCREMENT,
    `trainee_pid`           VARCHAR(17) NOT NULL,
    `trainee_character_uid` VARCHAR(96) NOT NULL,
    `department_key`        VARCHAR(64) NOT NULL DEFAULT 'tcsd',
    `phase`                 VARCHAR(64) NOT NULL DEFAULT 'Academy',
    `fto_pid`               VARCHAR(17) NOT NULL,
    `notes`                 TEXT NOT NULL,
    `updated_by_pid`        VARCHAR(17) NOT NULL,
    `active`                TINYINT NOT NULL DEFAULT 1,
    `insert_time`           TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at`            TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_training_roster` (`trainee_pid`,`trainee_character_uid`,`department_key`),
    INDEX `index_training_roster_department` (`department_key`,`active`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

INSERT INTO `players`
    (`pid`,`name`,`aliases`,`cash`,`bankacc`,`coplevel`,`mediclevel`,`civ_licenses`,`cop_licenses`,`med_licenses`,`civ_gear`,`cop_gear`,`med_gear`,`adminlevel`,`donorlevel`,`blacklist`)
VALUES
    ('76561198810688206','Community Owner','"[]"',0,1000000,'7','5','"[]"','"[]"','"[]"','"[]"','"[]"','"[]"','5','0',0)
ON DUPLICATE KEY UPDATE
    `name`='Community Owner',
    `coplevel`='7',
    `mediclevel`='5',
    `adminlevel`='5',
    `blacklist`=0;

INSERT INTO `steam_whitelist`
    (`pid`,`faction`,`level`,`permissions`,`active`,`notes`)
VALUES
    ('76561198810688206','community_owner',999,'["owner.access","owner.community","whitelist.override","jobs.override","leo.access","leo.department.tcsd","leo.rank.tcsd.sheriff","leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.owner","leo.training.view","leo.training.edit","leo.training.roster","staff.access","staff.whitelist","staff.permissions","staff.telemetry","police.access","police.cuff","police.ticket","police.warrant","police.search"]',1,'Community Owner bootstrap grant')
ON DUPLICATE KEY UPDATE
    `level`=999,
    `permissions`=VALUES(`permissions`),
    `active`=1,
    `notes`=VALUES(`notes`);

INSERT INTO `leo_memberships`
    (`pid`,`character_uid`,`department_key`,`rank_key`,`primary_subdivision`,`subdivisions`,`role_permissions`,`status`,`hired_by_pid`,`updated_by_pid`,`notes`)
VALUES
    ('76561198810688206','76561198810688206','tcsd','sheriff','patrol','["patrol","academy","hse","ert","ia","mcu","cid"]','["leo.command.terminal","leo.command.hire","leo.command.fire","leo.command.permissions","leo.command.owner","leo.training.view","leo.training.edit","leo.training.roster","staff.whitelist","staff.permissions"]','active','76561198810688206','76561198810688206','Community Owner and TCSD Sheriff bootstrap grant')
ON DUPLICATE KEY UPDATE
    `rank_key`='sheriff',
    `primary_subdivision`='patrol',
    `subdivisions`=VALUES(`subdivisions`),
    `role_permissions`=VALUES(`role_permissions`),
    `status`='active',
    `updated_by_pid`='76561198810688206',
    `notes`=VALUES(`notes`);

-- --------------------------------------------------------

--
-- Legal records surfaced by the HUD and ID card.
--

CREATE TABLE IF NOT EXISTS `citations` (
    `id`            INT NOT NULL AUTO_INCREMENT,
    `pid`           VARCHAR(17) NOT NULL,
    `character_uid` VARCHAR(96) NOT NULL,
    `officer_pid`   VARCHAR(17) NOT NULL,
    `amount`        INT NOT NULL DEFAULT 0,
    `reason`        TEXT NOT NULL,
    `status`        ENUM('pending','paid','void') NOT NULL DEFAULT 'pending',
    `insert_time`   TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at`    TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    INDEX `index_citation_status` (`pid`,`status`),
    CONSTRAINT `FK_characters_citations` FOREIGN KEY `fkIdx_characters_citations` (`character_uid`)
      REFERENCES `characters` (`character_uid`)
      ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT `FK_players_citations` FOREIGN KEY `fkIdx_players_citations` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `warrants` (
    `id`            INT NOT NULL AUTO_INCREMENT,
    `pid`           VARCHAR(17) NOT NULL,
    `character_uid` VARCHAR(96) NOT NULL,
    `issuer_pid`    VARCHAR(17) NOT NULL,
    `reason`        TEXT NOT NULL,
    `severity`      ENUM('low','medium','high','critical') NOT NULL DEFAULT 'medium',
    `active`        TINYINT NOT NULL DEFAULT 1,
    `insert_time`   TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `updated_at`    TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,

    PRIMARY KEY (`id`),
    INDEX `index_warrant_active` (`pid`,`active`),
    CONSTRAINT `FK_characters_warrants` FOREIGN KEY `fkIdx_characters_warrants` (`character_uid`)
      REFERENCES `characters` (`character_uid`)
      ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT `FK_players_warrants` FOREIGN KEY `fkIdx_players_warrants` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `vehicles`
--

CREATE TABLE IF NOT EXISTS `vehicles` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `pid`         VARCHAR(17) NOT NULL,
    `side`        VARCHAR(10) NOT NULL,
    `classname`   VARCHAR(64) NOT NULL,
    `type`        VARCHAR(16) NOT NULL,
    `alive`       TINYINT NOT NULL DEFAULT 1,
    `blacklist`   TINYINT NOT NULL DEFAULT 0,
    `active`      TINYINT NOT NULL DEFAULT 0,
    `plate`       MEDIUMINT NOT NULL,
    `color`       INT NOT NULL,
    `inventory`   TEXT NOT NULL,
    `gear`        TEXT NOT NULL,
    `fuel`        DOUBLE NOT NULL DEFAULT 1,
    `damage`      VARCHAR(256) NOT NULL,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    
    PRIMARY KEY (`id`),
    INDEX `fkIdx_players_vehicles` (`pid`),
    CONSTRAINT `FK_players_vehicles` FOREIGN KEY `fkIdx_players_vehicles` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE,
    INDEX `index_side` (`side`),
    INDEX `index_type` (`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `houses`
-- Needed for extDB latest update on git
--

CREATE TABLE IF NOT EXISTS `houses` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `pid`         VARCHAR(17) NOT NULL,
    `pos`         VARCHAR(32) DEFAULT NULL,
    `owned`       TINYINT DEFAULT 0,
    `garage`      TINYINT NOT NULL DEFAULT 0,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    
    PRIMARY KEY (`id`),
    INDEX `fkIdx_players_houses` (`pid`),
    CONSTRAINT `FK_players_houses` FOREIGN KEY `fkIdx_players_houses` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `gangs`
-- Needed for extDB latest update on git
--

CREATE TABLE IF NOT EXISTS `gangs` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `owner`       VARCHAR(17) NOT NULL,
    `name`        VARCHAR(32) DEFAULT NULL,
    `members`     TEXT,
    `maxmembers`  INT DEFAULT 8,
    `bank`        INT DEFAULT 0,
    `active`      TINYINT NOT NULL DEFAULT 1,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    
    PRIMARY KEY (`id`),
    UNIQUE KEY `unique_name` (`name`),
    INDEX `fkIdx_players_gangs` (`owner`),
    CONSTRAINT `FK_players_gangs` FOREIGN KEY `fkIdx_players_gangs` (`owner`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `containers`
-- Needed for extDB latest update on git
--

CREATE TABLE IF NOT EXISTS `containers` (
    `id`          INT NOT NULL AUTO_INCREMENT,
    `pid`         VARCHAR(17) NOT NULL,
    `classname`   VARCHAR(32) NOT NULL,
    `pos`         VARCHAR(32) DEFAULT NULL,
    `inventory`   TEXT NOT NULL,
    `gear`        TEXT NOT NULL,
    `dir`         VARCHAR(128) DEFAULT NULL,
    `active`      TINYINT NOT NULL DEFAULT 0,
    `owned`       TINYINT NOT NULL DEFAULT 0,
    `insert_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    
    PRIMARY KEY (`id`),
    INDEX `fkIdx_players_containers` (`pid`),
    CONSTRAINT `FK_players_containers` FOREIGN KEY `fkIdx_players_containers` (`pid`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `wanted`
-- Needed for extDB latest update on git
--

CREATE TABLE IF NOT EXISTS `wanted` (
    `wantedID`     VARCHAR(17) NOT NULL,
    `wantedName`   VARCHAR(32) NOT NULL,
    `wantedCrimes` TEXT NOT NULL,
    `wantedBounty` INT NOT NULL,
    `active`       TINYINT NOT NULL DEFAULT 0,
    `insert_time`  TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    
    PRIMARY KEY (`wantedID`),
    CONSTRAINT `FK_players_wanted` FOREIGN KEY `fkIdx_players_wanted` (`wantedID`)
      REFERENCES `players` (`pid`)
      ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------
--
-- Creates default user `arma3` with password `changeme` unless it already exists
-- Granting permissions to user `arma3`, created below
-- Reloads the privileges from the grant tables in the MySQL system database.
--

CREATE USER IF NOT EXISTS `arma3`@`localhost` IDENTIFIED BY 'changeme';
GRANT SELECT, UPDATE, INSERT, EXECUTE ON `altislife`.* TO 'arma3'@'localhost';
FLUSH PRIVILEGES;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
