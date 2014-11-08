INSERT INTO `trinity_string` (`entry`, `content_loc8`) VALUES ('66666', '|cFFFFFC00[AnticheatGear]|cFF00FFFF[|cFF60FF00%s|cFF00FFFF] Забанен за Cheat!|r');

INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 54933, 1, '0', '0', 'Harpun Spell');
INSERT INTO `spell_proc_event` (entry, procFlags) VALUES ('49028','69652');
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES 
(6770, -1784, 1, 'Sap(rank 1) removes Stealth'),
(2070, -1784, 1, 'Sap(rank 2) removes Stealth'),
(11297, -1784, 1, 'Sap(rank 3) removes Stealth'),
(51724, -1784, 1, 'Sap(rank 4) removes Stealth');

-- ## Fix MMaps
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37955,38434,38435,38436); -- Blood-Queen Lana'thel (ICC)
-- UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37813,38402,38582,38583); -- Deathbringer Saurfang (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (36853,38265,38266,38267); -- Sindragosa (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37533,38220); -- Rimefang (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37534,38219); -- Spinestalker (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (39747,39823); -- Saviana Ragefire (RS)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (10184,36538); -- Onyxia (Ony)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (24068,31655); -- Annhylde the Caller (UK)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (11583); -- Nefarian
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (27829); -- Ebon Gargyole
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (33293); -- XT002 (Ulduar)

INSERT INTO disables VALUES (7, 650, 0, '', '', 'Mmaps - Trial of the Champion');
INSERT INTO disables VALUES (7, 649, 0, '', '', 'Mmaps - Trial of the Crusader');

UPDATE `creature_template` SET `rank`='2' WHERE `entry` IN (37540,38128,38699,38700,37215,38129,38701,38702);

replace into `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) values('33236','34113','0','0','0','0','28580','28581','0','0','Steelforged Defender','','','0','80','80','2','1965','1965','0','1','0.857143','1','127','1','2000','1','1','255','32768','2048','0','0','0','0','0','255','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','3','1','20','20','1','1','608','1','0','0','0','0','0','0','0','121','1','0','0','','15595');

SET
@Entry = 190010,
@Name = "Warpweaver";

INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(@Entry, 19646, 0, @Name, "Transmogrifier", NULL, 0, 80, 80, 2, 35, 1, 1, 0, 0, 2000, 0, 1, 0, 7, 138936390, 0, 0, 0, '', 0, 3, 1, 0, 0, 1, 0, 0, 'Creature_Transmogrify');

SET @TEXT_ID := 50000;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES
(@TEXT_ID, 'Transmogrification allows you to change how your items look like without changing the stats of the items.\r\nItems used in transmogrification are no longer refundable, tradeable and are bound to you.\r\nUpdating a menu updates the view and prices.\r\n\r\nNot everything can be transmogrified with eachother.\r\nRestrictions include but are not limited to:\r\nOnly armor and weapons can be transmogrified\r\nGuns, bows and crossbows can be transmogrified with eachother\r\nFishing poles can not be transmogrified\r\nYou must be able to equip both items used in the process.\r\n\r\nTransmogrifications stay on your items as long as you own them.\r\nIf you try to put the item in guild bank or mail it to someone else, the transmogrification is stripped.\r\n\r\nYou can also remove transmogrifications for free at the transmogrifier.'),
(@TEXT_ID+1, 'You can save your own transmogrification sets.\r\n\r\nTo save, first you must transmogrify your equipped items.\r\nThen when you go to the set management menu and go to save set menu,\r\nall items you have transmogrified are displayed so you see what you are saving.\r\nIf you think the set is fine, you can click to save the set and name it as you wish.\r\n\r\nTo use a set you can click the saved set in the set management menu and then select use set.\r\nIf the set has a transmogrification for an item that is already transmogrified, the old transmogrification is lost.\r\nNote that same transmogrification restrictions apply when trying to use a set as in normal transmogrification.\r\n\r\nTo delete a set you can go to the set\'s menu and select delete set.');

SET @STRING_ENTRY := 11100;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(@STRING_ENTRY+0, 'Item transmogrified'),
(@STRING_ENTRY+1, 'Equipment slot is empty'),
(@STRING_ENTRY+2, 'Invalid source item selected'),
(@STRING_ENTRY+3, 'Source item does not exist'),
(@STRING_ENTRY+4, 'Destination item does not exist'),
(@STRING_ENTRY+5, 'Selected items are invalid'),
(@STRING_ENTRY+6, 'Not enough money'),
(@STRING_ENTRY+7, 'You don\'t have enough tokens'),
(@STRING_ENTRY+8, 'Transmogrifications removed'),
(@STRING_ENTRY+9, 'There are no transmogrifications'),
(@STRING_ENTRY+10, 'Invalid name inserted');

UPDATE `trinity_string` SET `content_loc8`='|cffffff00[|c00077766Автоматическое сообщение|cffffff00]: |cFFF222FF%s|r' WHERE (`entry`='11000');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000|wowgear project| %s дал мут %s на %u минут, |cffff0000 по причине: %s|r' WHERE (`entry`='11003');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000|wowgear project| %s дал бан %s на %s, |cffff0000 по причине: %s|r' WHERE (`entry`='11006');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000[Бг-Аннонс]:|r %s -- [%u-%u] A: %u/%u, H: %u/%u|r' WHERE (`entry`='712');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000[Бг-Аннонс]:|r %s -- [%u-%u] Started!|r' WHERE (`entry`='717');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000|wowgear project| %s дал бан %s permanetly, |cffff0000 по причине: %s|r' WHERE (`entry`='11007');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000|wowgear project| %s дал бан персонажу %s permanetly, |cffff0000 по причине: %s|r' WHERE (`entry`='11005');
UPDATE `trinity_string` SET `content_loc8`='|cffffff00[|c1f40af20Аннонс от|r |cffff0000%s|cffffff00]:|r %s|r' WHERE (`entry`='787');
UPDATE `trinity_string` SET `content_loc8`='Время работы: %s' WHERE (`entry`='13');
UPDATE `trinity_string` SET `content_loc8`='[wowgear] %s' WHERE (`entry`='3');
UPDATE `trinity_string` SET `content_loc8`='Онлайн игроков: %u (максимум: %u)' WHERE (`entry`='60');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000[Арена-Аннонс]:|r %s -- Joined : %ux%u : %u|r' WHERE (`entry`='718');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000[Арена-Аннонс]:|r %s -- Exited : %ux%u : %u|r' WHERE (`entry`='719');
UPDATE `trinity_string` SET `content_loc8`='|cffff0000|wowgear project| %s дал бан персонажу %s на %s, |cffff0000  по причине: %s|r' WHERE (`entry`='11004');
UPDATE `trinity_string` SET `content_loc8`='|Hplayer:$N|h[$N]|h получил достижение $a!' WHERE (`entry`='810');

SET @ITEM := 50274; -- Shadowfrost Shard
UPDATE `creature_loot_template` SET `Chance`=38 WHERE `entry` IN
(38297,37959,37506,38550,38785,38436,38586,38267,39168) and`item`=@ITEM;
UPDATE `creature_loot_template` SET `Chance`=68 WHERE `entry` IN
(37957,37504,38106,38390,38431,38401,38434,38265,39166) and`item`=@ITEM;

UPDATE `conditions` SET `ConditionValue2`=1 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10383 AND `SourceEntry`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=1 AND `ConditionValue1`=63663;

-- last merge 2014_10_21_00_world