SET @TSUPREMO = 900030;
DELETE FROM `creature_template` WHERE entry = @TSUPREMO;
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `scale`, `unit_class`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `ScriptName`) VALUES
(@TSUPREMO,'18998','Великий тренер Jacob','Научу любому заклинанию','1','80','2','35','177','0.4','128','1','0','0','0','2','npc_treinador_supremo');

SET @TSUPREMO = 900030;
SET @GUID := (SELECT MIN(guid) FROM `creature` WHERE id = @TSUPREMO);
DELETE FROM creature_addon WHERE guid = @GUID;

INSERT INTO `creature_addon` (`guid`, `bytes2`, `auras`) VALUES
(@GUID,'4097','46934');

REPLACE INTO `npc_text` (`ID`, `text0_0`) VALUES
('11110','Приветствую |cff1E90FF$n:|r\r\nЯ великий тренер Jacob\r\nНаучу любому заклинанию\r\nУ меня ты сможешь изучить любому заклинание, а также разучить его!');

UPDATE `trinity_string` SET `content_loc8`='|cFFFFFC00[AnticheatGear]|cFF00FFFF[|cFF60FF00%s|cFF00FFFF] Забанен за Cheat!|r' WHERE (`entry`='66666');

INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 54933, 1, '0', '0', 'Harpun Spell');
INSERT INTO `spell_proc_event` (entry, procFlags) VALUES ('49028','69652');
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES 
(6770, -1784, 1, 'Sap(rank 1) removes Stealth'),
(2070, -1784, 1, 'Sap(rank 2) removes Stealth'),
(11297, -1784, 1, 'Sap(rank 3) removes Stealth'),
(51724, -1784, 1, 'Sap(rank 4) removes Stealth');

-- INSERT INTO `creature_loot_template` VALUES ('24664', '35513', '50', '1', '0', '1', '1');