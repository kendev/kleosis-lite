/*
-- Query: SELECT * FROM `kleoport`.`ks_class_schedule`
LIMIT 0, 1000
*/
/*
* Be sure to change the kccls_id_fk and period_lead values before importing...
*
1168 - Kleosis sample Art 101 Class - Section 1
1101 - Kleosis sample English 101 Class - Section 1
1107 - Kleosis sample English 102 Class - Section 1
1090 - Kleosis sample Math 101 Class - Section 1
1110 - Kleosis sample Science 101 Class - Section 1
1172 - Kleosis sample PE 101 Class - Section 1
1175 - Kleosis sample Music 101 Class - Section 1
1192 - Kleosis sample Computer 101 Class - Section 1
1186 - Kleosis Homeroom-Morning Attnd G-9 Class - Sec 1
1196 - Kleosis Homeroom-Afternoon Attnd G-9 Class - Sec 1

1117 - Kleosis sample Art 201 Class - Section 1
1140 - Kleosis sample English 201 Class - Section 1
1146 - Kleosis sample English 202 Class - Section 1
1129 - Kleosis sample Math 201 Class - Section 1
1149 - Kleosis sample Science 201 Class - Section 1
1179 - Kleosis sample PE 201 Class - Section 1
1182 - Kleosis sample Music 201 Class - Section 1
1194 - Kleosis sample Computer 201 Class - Section 1
1189 - Kleosis Homeroom-Morning Attnd G-10 Class - Sec 1
1199 - Kleosis Homeroom-Afternoon Attnd G-10 Class - Sec 1

880 - instructor8400
881 - instructor8401
882 - instructor8402
883 - instructor8403
884 - instructor8404
885 - instructor8405
886 - instructor8406
887 - instructor8407
888 - instructor8408
889 - instructor8409

*  kclss_id, kccls_id_fk, period_start_datetime, period_end_time, period_day, period_hour, period_length, period_status, classroom, period_lead, period_sub
*/
use kleoport;

INSERT INTO ks_class_schedule VALUES (1, 1101, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 1, 0, 0, 1, 2, 880, 0);
INSERT INTO ks_class_schedule VALUES (2, 1101, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 2, 0, 0, 1, 2, 880, 0);
INSERT INTO ks_class_schedule VALUES (3, 1101, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 3, 0, 0, 1, 2, 880, 0);
INSERT INTO ks_class_schedule VALUES (4, 1101, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 4, 0, 0, 1, 2, 880, 0);
INSERT INTO ks_class_schedule VALUES (5, 1101, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 5, 0, 0, 1, 2, 880, 0);
INSERT INTO ks_class_schedule VALUES (6, 1090, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 1, 0, 0, 1, 2, 881, 0);
INSERT INTO ks_class_schedule VALUES (7, 1090, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 2, 0, 0, 1, 2, 881, 0);
INSERT INTO ks_class_schedule VALUES (8, 1090, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 3, 0, 0, 1, 2, 881, 0);
INSERT INTO ks_class_schedule VALUES (9, 1090, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 4, 0, 0, 1, 2, 881, 0);
INSERT INTO ks_class_schedule VALUES (10, 1090, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 5, 0, 0, 1, 2, 881, 0);
INSERT INTO ks_class_schedule VALUES (11, 1168, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 1, 0, 0, 1, 2, 883, 0);
INSERT INTO ks_class_schedule VALUES (12, 1168, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 2, 0, 0, 1, 2, 883, 0);
INSERT INTO ks_class_schedule VALUES (13, 1168, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 3, 0, 0, 1, 2, 883, 0);
INSERT INTO ks_class_schedule VALUES (14, 1168, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 5, 0, 0, 1, 2, 883, 0);
INSERT INTO ks_class_schedule VALUES (15, 1110, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 3, 0, 0, 1, 2, 882, 0);
INSERT INTO ks_class_schedule VALUES (16, 1110, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 4, 0, 0, 1, 2, 882, 0);
INSERT INTO ks_class_schedule VALUES (17, 1110, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 5, 0, 0, 1, 2, 882, 0);
INSERT INTO ks_class_schedule VALUES (18, 1110, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 1, 0, 0, 1, 2, 882, 0);
INSERT INTO ks_class_schedule VALUES (19, 1110, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 2, 0, 0, 1, 1, 882, 0);
INSERT INTO ks_class_schedule VALUES (20, 1172, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 4, 0, 0, 1, 2, 884, 0);
INSERT INTO ks_class_schedule VALUES (21, 1172, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 1, 0, 0, 1, 2, 884, 0);
INSERT INTO ks_class_schedule VALUES (22, 1192, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 2, 0, 0, 1, 0, 885, 0);
INSERT INTO ks_class_schedule VALUES (23, 1192, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 3, 0, 0, 1, 0, 885, 0);
INSERT INTO ks_class_schedule VALUES (24, 1175, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 4, 0, 0, 1, 1, 886, 0);
INSERT INTO ks_class_schedule VALUES (25, 1175, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 5, 0, 0, 1, 1, 886, 0);
INSERT INTO ks_class_schedule VALUES (26, 1107, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 1, 0, 0, 1, 2, 887, 0);
INSERT INTO ks_class_schedule VALUES (27, 1107, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 2, 0, 0, 1, 2, 887, 0);
INSERT INTO ks_class_schedule VALUES (28, 1107, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 3, 0, 0, 1, 2, 887, 0);
INSERT INTO ks_class_schedule VALUES (29, 1107, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 4, 0, 0, 1, 2, 887, 0);
INSERT INTO ks_class_schedule VALUES (30, 1107, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 5, 0, 0, 1, 2, 887, 0);
INSERT INTO ks_class_schedule VALUES (31, 1149, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 1, 0, 0, 1, 3, 882, 0);
INSERT INTO ks_class_schedule VALUES (32, 1149, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 2, 0, 0, 1, 3, 882, 0);
INSERT INTO ks_class_schedule VALUES (33, 1149, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 3, 0, 0, 1, 3, 882, 0);
INSERT INTO ks_class_schedule VALUES (34, 1149, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 4, 0, 0, 1, 3, 882, 0);
INSERT INTO ks_class_schedule VALUES (35, 1149, '2011-08-07 08:15:00', '2011-08-07 09:05:00', 5, 0, 0, 1, 3, 882, 0);
INSERT INTO ks_class_schedule VALUES (36, 1179, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 1, 0, 0, 1, 3, 884, 0);
INSERT INTO ks_class_schedule VALUES (37, 1179, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 5, 0, 0, 1, 3, 884, 0);
INSERT INTO ks_class_schedule VALUES (38, 1182, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 2, 0, 0, 1, 1, 886, 0);
INSERT INTO ks_class_schedule VALUES (39, 1182, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 1, 0, 0, 1, 1, 886, 0);
INSERT INTO ks_class_schedule VALUES (40, 1129, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 3, 0, 0, 1, 3, 881, 0);
INSERT INTO ks_class_schedule VALUES (41, 1129, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 4, 0, 0, 1, 3, 881, 0);
INSERT INTO ks_class_schedule VALUES (42, 1129, '2011-08-07 09:10:00', '2011-08-07 10:00:00', 5, 0, 0, 1, 3, 881, 0);
INSERT INTO ks_class_schedule VALUES (43, 1129, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 1, 0, 0, 1, 3, 881, 0);
INSERT INTO ks_class_schedule VALUES (44, 1129, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 2, 0, 0, 1, 3, 881, 0);
INSERT INTO ks_class_schedule VALUES (45, 1140, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 1, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (46, 1140, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 2, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (47, 1140, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 3, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (48, 1140, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 4, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (49, 1140, '2011-08-07 10:30:00', '2011-08-07 11:20:00', 5, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (50, 1194, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 3, 0, 0, 1, 4, 885, 0);
INSERT INTO ks_class_schedule VALUES (51, 1194, '2011-08-07 11:25:00', '2011-08-07 12:15:00', 4, 0, 0, 1, 4, 885, 0);
INSERT INTO ks_class_schedule VALUES (52, 1146, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 1, 0, 0, 1, 3, 887, 0);
INSERT INTO ks_class_schedule VALUES (53, 1146, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 2, 0, 0, 1, 3, 887, 0);
INSERT INTO ks_class_schedule VALUES (54, 1146, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 3, 0, 0, 1, 3, 887, 0);
INSERT INTO ks_class_schedule VALUES (55, 1146, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 4, 0, 0, 1, 3, 887, 0);
INSERT INTO ks_class_schedule VALUES (56, 1146, '2011-08-07 13:35:00', '2011-08-07 14:25:00', 5, 0, 0, 1, 3, 887, 0);
INSERT INTO ks_class_schedule VALUES (57, 1117, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 3, 0, 0, 1, 3, 888, 0);
INSERT INTO ks_class_schedule VALUES (58, 1117, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 4, 0, 0, 1, 3, 888, 0);
INSERT INTO ks_class_schedule VALUES (59, 1117, '2011-08-07 14:30:00', '2011-08-07 15:20:00', 5, 0, 0, 1, 3, 888, 0);
INSERT INTO ks_class_schedule VALUES (60, 1186, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 1, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (61, 1186, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 2, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (62, 1186, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 3, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (63, 1186, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 4, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (64, 1186, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 5, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (65, 1189, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 1, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (66, 1189, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 2, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (67, 1189, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 3, 0, 0, 1, 3, 882, 0);
INSERT INTO ks_class_schedule VALUES (68, 1189, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 4, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (69, 1189, '2011-08-07 08:00:00', '2011-08-07 08:15:00', 5, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (70, 1196, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 1, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (71, 1196, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 2, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (72, 1196, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 3, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (73, 1196, '2011-08-18 13:30:00', '2011-08-18 13:35:00', 4, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (74, 1196, '2011-08-18 13:00:00', '2011-08-18 13:35:00', 5, 0, 0, 1, 3, 880, 0);
INSERT INTO ks_class_schedule VALUES (75, 1199, '2011-09-28 13:30:00', '2011-09-28 13:35:00', 1, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (76, 1199, '2011-09-28 13:30:00', '2011-09-28 13:35:00', 2, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (77, 1199, '2011-09-28 13:00:00', '2011-09-28 13:35:00', 3, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (78, 1199, '2011-09-28 13:00:00', '2011-09-28 13:35:00', 4, 0, 0, 1, 4, 882, 0);
INSERT INTO ks_class_schedule VALUES (79, 1199, '2011-09-28 13:00:00', '2011-09-28 13:35:00', 5, 0, 0, 1, 4, 882, 0);


insert into ks_student_course_class_grades values (0,2,0.0,88.00,91.5,0.0,0.0,0.0,90.63,'Good job.');
insert into ks_student_course_class_grades values (0,4,0.0,86.00,91.25,0.0,0.0,0.0,90.13,'Good work.');
