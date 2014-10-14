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