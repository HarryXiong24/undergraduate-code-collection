/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50722
Source Host           : 127.0.0.1:3306
Source Database       : travel

Target Server Type    : MYSQL
Target Server Version : 50722
File Encoding         : 65001

Date: 2018-08-14 13:35:59
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `pwd` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('1', 'mr', 'pbkdf2:sha256:50000$TkExX9Jm$d63477853a17dcaedcd52be4b6213ebb74b61a12456762ac19d6b7dfb559aa57');

-- ----------------------------
-- Table structure for adminlog
-- ----------------------------
DROP TABLE IF EXISTS `adminlog`;
CREATE TABLE `adminlog` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `admin_id` int(11) DEFAULT NULL,
  `ip` varchar(100) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `ix_adminlog_addtime` (`addtime`),
  KEY `admin_id` (`admin_id`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of adminlog
-- ----------------------------
INSERT INTO `adminlog` VALUES ('1', '1', '127.0.0.1', '2018-03-24 09:26:24');
INSERT INTO `adminlog` VALUES ('2', '1', '127.0.0.1', '2018-03-24 09:27:09');
INSERT INTO `adminlog` VALUES ('3', '1', '127.0.0.1', '2018-03-24 09:29:42');
INSERT INTO `adminlog` VALUES ('4', '1', '127.0.0.1', '2018-08-09 14:52:55');
INSERT INTO `adminlog` VALUES ('5', '1', '127.0.0.1', '2018-08-10 08:45:20');
INSERT INTO `adminlog` VALUES ('6', '1', '127.0.0.1', '2018-08-10 10:02:37');
INSERT INTO `adminlog` VALUES ('7', '1', '127.0.0.1', '2018-08-10 10:38:04');
INSERT INTO `adminlog` VALUES ('8', '1', '127.0.0.1', '2018-08-10 10:53:51');
INSERT INTO `adminlog` VALUES ('9', '1', '127.0.0.1', '2018-08-11 10:53:35');
INSERT INTO `adminlog` VALUES ('10', '1', '127.0.0.1', '2018-08-13 14:14:36');
INSERT INTO `adminlog` VALUES ('11', '1', '127.0.0.1', '2018-08-14 09:17:10');
INSERT INTO `adminlog` VALUES ('12', '1', '127.0.0.1', '2018-08-14 11:04:20');
INSERT INTO `adminlog` VALUES ('13', '1', '127.0.0.1', '2018-08-14 13:28:49');

-- ----------------------------
-- Table structure for alembic_version
-- ----------------------------
DROP TABLE IF EXISTS `alembic_version`;
CREATE TABLE `alembic_version` (
  `version_num` varchar(32) NOT NULL,
  PRIMARY KEY (`version_num`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of alembic_version
-- ----------------------------
INSERT INTO `alembic_version` VALUES ('423caff1b936');

-- ----------------------------
-- Table structure for area
-- ----------------------------
DROP TABLE IF EXISTS `area`;
CREATE TABLE `area` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  `is_recommended` tinyint(1) DEFAULT NULL,
  `introduction` text,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`),
  KEY `ix_area_addtime` (`addtime`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of area
-- ----------------------------
INSERT INTO `area` VALUES ('1', '北京', '2018-03-22 10:45:33', '1', '今日的北京，已发展成为一座现代化的大都市：北京大学、清华大学、中国科学院等教育和科研机构座落于北京市区；金融街是中国金融监管机构办公地点和金融业聚集地；北京商务中心区是北京经济的象征；798艺术区是世界知名的当代艺术中心；此外，中国国家大剧院、北京首都国际机场3号航站楼、中央电视台总部大楼、“鸟巢”、“水立方”、中国尊等具有现代风格的建筑成为古老北京新的名片。每年有超过1亿4700万人到北京旅游。');
INSERT INTO `area` VALUES ('2', '长春', '2018-03-22 11:40:13', '1', '长春，被誉为“北国春城”，绿化率居于亚洲大城市前列，中国四大园林城市之一；连续十次蝉联“中国最具幸福感城市”；“中国制造2025”试点城市；“首批全国城市设计试点城市”；位列《2015中国自然指数》中国十大科研城市第六位。');
INSERT INTO `area` VALUES ('3', '天津', '2018-08-10 09:31:59', '1', '这是天津');

-- ----------------------------
-- Table structure for collect
-- ----------------------------
DROP TABLE IF EXISTS `collect`;
CREATE TABLE `collect` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `scenic_id` int(11) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `ix_collect_addtime` (`addtime`),
  KEY `scenic_id` (`scenic_id`),
  KEY `user_id` (`user_id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of collect
-- ----------------------------
INSERT INTO `collect` VALUES ('3', '1', '7', '2018-08-13 09:25:14');

-- ----------------------------
-- Table structure for oplog
-- ----------------------------
DROP TABLE IF EXISTS `oplog`;
CREATE TABLE `oplog` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `admin_id` int(11) DEFAULT NULL,
  `ip` varchar(100) DEFAULT NULL,
  `reason` varchar(600) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `ix_oplog_addtime` (`addtime`),
  KEY `admin_id` (`admin_id`)
) ENGINE=MyISAM AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of oplog
-- ----------------------------
INSERT INTO `oplog` VALUES ('1', '1', '127.0.0.1', '添加景区八达岭长城', '2018-03-24 11:19:05');
INSERT INTO `oplog` VALUES ('2', '1', '127.0.0.1', '添加地区天津', '2018-03-24 11:23:57');
INSERT INTO `oplog` VALUES ('3', '1', '127.0.0.1', '添加景区颐和园', '2018-03-24 13:01:27');
INSERT INTO `oplog` VALUES ('4', '1', '127.0.0.1', '添加景区净月潭国家森林公园', '2018-03-24 13:05:54');
INSERT INTO `oplog` VALUES ('5', '1', '127.0.0.1', '添加景区伪满皇宫博物院', '2018-03-24 13:10:08');
INSERT INTO `oplog` VALUES ('6', '1', '127.0.0.1', '添加游记最轻松愉快的方式游览故宫', '2018-03-24 13:24:56');
INSERT INTO `oplog` VALUES ('7', '1', '127.0.0.1', '添加景区狗不理包子', '2018-08-10 09:03:35');
INSERT INTO `oplog` VALUES ('8', '1', '127.0.0.1', '删除地区天津', '2018-08-10 09:04:22');
INSERT INTO `oplog` VALUES ('9', '1', '127.0.0.1', '删除地区天津', '2018-08-10 09:31:23');
INSERT INTO `oplog` VALUES ('10', '1', '127.0.0.1', '添加地区大连', '2018-08-10 09:50:41');
INSERT INTO `oplog` VALUES ('11', '1', '127.0.0.1', '删除地区大连', '2018-08-10 10:02:48');
INSERT INTO `oplog` VALUES ('12', '1', '127.0.0.1', '删除意见建议', '2018-08-10 10:55:42');
INSERT INTO `oplog` VALUES ('13', '1', '127.0.0.1', '添加地区东京', '2018-08-10 10:57:46');
INSERT INTO `oplog` VALUES ('14', '1', '127.0.0.1', '删除地区东京', '2018-08-10 10:58:50');
INSERT INTO `oplog` VALUES ('15', '1', '127.0.0.1', '删除景区狗不理包子', '2018-08-10 13:31:18');
INSERT INTO `oplog` VALUES ('16', '1', '127.0.0.1', '删除意见建议', '2018-08-14 10:17:17');

-- ----------------------------
-- Table structure for scenic
-- ----------------------------
DROP TABLE IF EXISTS `scenic`;
CREATE TABLE `scenic` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) DEFAULT NULL,
  `star` int(11) DEFAULT NULL,
  `logo` varchar(255) DEFAULT NULL,
  `introduction` text,
  `content` text,
  `address` text,
  `is_hot` tinyint(1) DEFAULT NULL,
  `is_recommended` tinyint(1) DEFAULT NULL,
  `area_id` int(11) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `logo` (`logo`),
  UNIQUE KEY `title` (`title`),
  KEY `ix_scenic_addtime` (`addtime`),
  KEY `area_id` (`area_id`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of scenic
-- ----------------------------
INSERT INTO `scenic` VALUES ('1', '故宫博物院', '4', '20180814133357a1167f9d31c7472eb2b482571696b050', '故宫又名紫禁城，是中国乃至世界上保存最完整，规模最大的木质结构古建筑群，被誉为“世界五大宫之首”。\r\n故宫由永乐帝朱棣下令建造，依据其布局与功用分为“外朝”与“内廷”两大部分。以乾清门为界，乾清门以南为外朝，以北为内廷。\r\n外朝也称为“前朝”，以太和殿(金銮殿)、中和殿、保和殿三大殿为中心，是封建皇帝行使权力、举行盛典的地方。\r\n内廷以乾清宫、交泰殿、坤宁宫后三宫为中心，以及东西两侧的东六宫和西六宫，是封建帝王与后妃居住之所，也就是俗称的“三宫六院”。\r\n故宫内珍藏有大量珍贵文物，据统计有上百万件，占全国文物总数的六分之一。钟表馆每天11点和14点有钟表演示，不可错过。', '<p>北京故宫是中国明清两代的皇家宫殿，旧称为紫禁城，位于北京中轴线的中心，是中国古代宫廷建筑之精华。北京故宫以三大殿为中心，占地面积72万平方米，建筑面积约15万平方米，有大小宫殿七十多座，房屋九千余间。是世界上现存规模最大、保存最为完整的木质结构古建筑之一。<br />\r\n北京故宫于明成祖永乐四年（1406年）开始建设，以南京故宫为蓝本营建，到永乐十八年（1420年）建成。它是一座长方形城池，南北长961米，东西宽753米，四面围有高10米的城墙，城外有宽52米的护城河。紫禁城内的建筑分为外朝和内廷两部分。外朝的中心为太和殿、中和殿、保和殿，统称三大殿，是国家举行大典礼的地方。内廷的中心是乾清宫、交泰殿、坤宁宫，统称后三宫，是皇帝和皇后居住的正宫。<br />\r\n北京故宫被誉为世界五大宫之首（北京故宫、法国凡尔赛宫、英国白金汉宫、美国白宫、俄罗斯克里姆林宫），是国家AAAAA级旅游景区， 1961年被列为第一批全国重点文物保护单位，1987年被列为世界文化遗产。</p>\r\n\r\n<p><img alt=\"\" src=\"/static/uploads/ckeditor/201803240935436d8289e1792e4a7ca38dbb90855404dd.jpg\" style=\"height:454px; width:1258px\" /></p>\r\n\r\n<blockquote>\r\n<h2><strong>旅游须知：</strong></h2>\r\n\r\n<p><big>电话：010-85007421</big></p>\r\n\r\n<p><big>网址：<a href=\"http://www.dpm.org.cn/\" target=\"_blank\">http://www.dpm.org.cn</a></big></p>\r\n\r\n<p><big>开放时间：除法定节假日和暑期（每年7月1日至8月31日）外，故宫博物院全年实行周一全天闭馆的措施。</big></p>\r\n\r\n<p><big>门票：（1）每年4月1日至10月31日为旺季，大门票60元/人；<br />\r\n（2）每年11月1日至次年3月31日为淡季，大门票40元/人。</big></p>\r\n</blockquote>\r\n', '北京市东城区景山前街4号', '1', '1', '1', '2018-03-22 12:48:16');
INSERT INTO `scenic` VALUES ('2', '八达岭长城', '5', '2018081110544934001363864d498aaef4076eb0691469.jpg', '八达岭长城是明长城中保存最好的一段，也是最具代表性的一段，是长城重要关口居庸关的前哨，海拔高达1015米，地势险要，城关坚固，历来是兵家必争之地。登上八达岭长城，极目远望，山峦起伏，雄沉刚劲的北方山势绵延不绝。八达岭长城因山势而雄伟，山势因长城更加险峻。“不到长城非好汉”，八达岭长城是古今中外各界人士到北京游览的必到之所，迄今为止，已有包括尼克松、撒切尔夫人等在内的三百多位世界知名人士曾登上八达岭长城一览这里的山河秀色。', '<p>八达岭最著名的是它的长城。它是中国开放最早的一段长城，也是至今为止保护最好，最著名的一段明代长城。其可行部分全长3741米。它建于1504年，关城有东西二门，东门额题&ldquo;居庸外镇&rdquo;，刻于嘉靖十八年（1539年）；西门额题&ldquo;北门锁钥&rdquo;，刻于万历十年（1582年）。<br />\r\n万里长城八达岭段建于1505年（明朝弘治十八年），东窄西宽，有东西二门，南北两面各开一豁口，接连关城城墙，台上四周有砖砌垛口。城墙顶部地面铺缦方砖，嵌缝密实。内侧为宇墙，外侧为垛墙，垛墙上方有垛口，下方有射洞。城墙高低宽窄不一，平均高7米多，有些地段高达14米。墙基平均宽6.5米，顶宽5米多，可容五马并驰或十人并进。<br />\r\n八达岭和附近的长城被称为燕京八景之一的居庸叠翠。</p>\r\n\r\n<p><img alt=\"\" src=\"/static/uploads/ckeditor/201803241117457230a0ef87ce408eb920e45593fce6dc.jpg\" style=\"height:173px; width:291px\" />&nbsp; &nbsp; &nbsp;<img alt=\"\" src=\"/static/uploads/ckeditor/201803241118181610a8b216f341eeb7d055ba2a73a97a.jpg\" style=\"height:180px; width:280px\" /></p>\r\n\r\n<h2><strong>旅游须知：</strong></h2>\r\n\r\n<blockquote>\r\n<ul>\r\n	<li>\r\n	<p>电话</p>\r\n\r\n	<p>010-69121383;010-69121226</p>\r\n	</li>\r\n	<li>\r\n	<p>网址</p>\r\n\r\n	<p><a href=\"http://www.badaling.cn/\" target=\"_blank\">http://www.badaling.cn</a></p>\r\n	</li>\r\n	<li>\r\n	<p>门票</p>\r\n\r\n	<p>淡季（11-次年3月）35元/人，旺季（4-10月）40元/人<br />\r\n	淡季学生及老人等17.5元/人；旺季学生及老人等20元/人</p>\r\n	</li>\r\n	<li>\r\n	<p>开放时间</p>\r\n\r\n	<p>旺季（4~10月）：06:30~19:00<br />\r\n	淡季（11~3月）：07:00~18:00</p>\r\n	</li>\r\n</ul>\r\n</blockquote>\r\n', '北京市延庆县军都山关沟古道北口', '1', '1', '1', '2018-03-24 11:19:05');
INSERT INTO `scenic` VALUES ('3', '颐和园', '4', '20180324130127eb365ba129fb4636a8f033e111c8efa2.jpg', '颐和园坐落于北京西郊，是中国古典园林之首，总面积约290公顷，由万寿山和昆明湖组成。全园分3个区域：以仁寿殿为中心的政治活动区；以玉澜堂、乐寿堂为主体的帝后生活区；以万寿山和昆明湖组成的风景旅游区。全园以西山群峰为背景，加之建筑群与园内山湖形势融为一体，使景色变幻无穷。1998年12月2日列入《世界遗产名录》。', '<p>颐和园以万寿山和昆明湖为主，昆明湖占颐和园总面积的四分之三。除了湖山，还有殿堂景区、耕织图景区。重要建筑集中在万寿山南北中轴线上。万寿山分为前山、后山两部分，前山自东向西有养云轩、无尽意轩、介寿堂、排云殿、清华轩、宝云阁、共一楼、听鹂馆、画中游等知名景观。后山南北中轴线为规模宏大的汉藏风格寺庙殿宇，包括四大部洲、须弥灵境、香岩宗印之阁等等，周围点缀以数座小型山间园林，有苏州街、寅辉城关、花承阁、赅春园、绘芳堂等建筑。昆明湖中有三座岛屿，分别名为南湖岛、藻鉴堂岛、治镜阁岛。昆明湖由一条西堤将大湖一分为二，光绪时建立围墙，修筑起了东堤。<br />\r\n颐和园的主要区域可包括六个部分，分别是殿堂景区（是帝后料理朝政和住宿所在）、万寿山景区、昆明湖景区、耕织图景区（独特的农牧色彩）、长廊景区和中轴景区（起于前山云辉玉宇牌楼，止于后山慈福慧因牌楼）。作为一座知名园林博物馆，拥有丰富制式的园林建筑和景观营造手法，涵盖了中国传统名著中的亭台楼阁，轩榭台堂。</p>\r\n\r\n<p><img alt=\"\" src=\"/static/uploads/ckeditor/20180324130057a797628bce3446ebae3b149d8c6e5358.jpeg\" style=\"height:370px; width:690px\" /></p>\r\n', '北京市海淀区新建宫门路19号', '1', '1', '1', '2018-03-24 13:01:27');
INSERT INTO `scenic` VALUES ('4', '净月潭国家森林公园', '5', '20180324130554b0efff8d6f114c34802ee773dbe996e2.jpeg', '净月潭因其弯月状而得名，被誉为台湾日月潭的姊妹潭。公园内树木茂盛、空气清新，处处皆景致，四季貌不同。\r\n地貌呈低山丘陵状，有大小山峰119座，其中海拔高于200米的就有近120座，而独以潭北的山色为最。这里有86座山岭自北向南延伸至潭边，不仅沟壑纵横，层峦叠嶂，而且可以登山鸟瞰潭水全景。\r\n整座山仿佛巨蟒蜿蜒，其中犹以大架山海拔最高，是绝佳的度假胜地。此外，园内植物格局模拟长白山植物垂地分布特征，有山花、药用植物等千余种。', '<p>净月潭景区位于吉林省长春市东南部长春净月经济开发区，距市中心人民广场仅18公里，景区面积为96.38平方公里，其中水域面积为5.3平方公里，森林覆盖率达到96%以上。净月潭因形似弯月状而得名，与台湾日月潭互为姊妹潭。<br />\r\n净月潭是在1934年由人工修建的第一座为长春市城区供水的水源地，在沦陷时期称&rdquo;水源地&ldquo;或&rdquo;贮水池&ldquo;。净月潭的名字是由&rdquo;满洲国总理大臣&ldquo;郑孝胥的二儿子，时任&rdquo;满洲国国都建设局局长&ldquo;的郑禹所起。景区内的森林为人工建造，含有30个树种的完整森林生态体系，得天独厚的区位优势，使之成为&ldquo;喧嚣都市中的一块净土&rdquo;，有&ldquo;亚洲第一大人工林海&rdquo;、&ldquo;绿海明珠&rdquo;、&ldquo;都市氧吧&rdquo;之美誉，是长春市的生态绿核和城市名片。<br />\r\n净月潭景区处处皆景致，四季貌不同。亚洲最大的人工森林与山、水相依的生态景象构成了净月潭四季变幻的风情画卷。净月潭已然成为春踏青、夏避暑、秋赏景、冬玩冰雪的理想去处。<br />\r\n净月潭不仅是生态休闲中心，更是体育健身的中心，作为长春市消夏节和长春冰雪节的主场地，相继开展了净月潭瓦萨国际滑雪节、净月潭森林马拉松、净月潭森林定向赛、净月潭自行车马拉松、青少年阳光体育大会、龙舟赛、旅游大集等赛事和活动，致力于倡导健康、时尚、休闲的生活方式，打造国际知名旅游文化活动的聚集地。</p>\r\n\r\n<p><img alt=\"\" src=\"/static/uploads/ckeditor/2018032413055096c1be099bdf427d8cdd3e985d76cae0.jpg\" style=\"height:125px; width:402px\" /></p>\r\n', '吉林省长春市净月开发区', '1', '1', '2', '2018-03-24 13:05:54');
INSERT INTO `scenic` VALUES ('5', '伪满皇宫博物院', '5', '20180324131008f4e5802528d847279cdfb84d8974cdc1.jpeg', '伪满皇宫博物院的主要建筑有勤民楼、缉熙楼、怀远楼、嘉乐殿、同德殿、书画库、莱薰门、保康门、兴运门、建国神庙遗迹和御用防空洞等，对游客开放的还有跑马场和东北沦陷史陈列馆。', '<p>1931年九一八事变后，日本扶植清朝末代皇帝爱新觉罗&middot;溥仪建立满洲国，以此控制中国东北。当时的中华民国及1949年成立的中华人民共和国均不承认满洲国，所以称其为&ldquo;伪满洲国&rdquo;或&ldquo;伪满&rdquo;。1932年3月9日溥仪就任满洲国执政，4月3日执政府迁入原吉黑榷运局官署（民国时期管理吉林、黑龙江两省盐务）旧址。1934年3月1日溥仪称帝，执政府机关改为宫内府。因日本天皇的宫廷叫皇宫，溥仪的这个宫廷就只能对外称为&ldquo;帝宫&rdquo;。至1945年8月日本投降前，满洲国帝宫一直作为溥仪办公和生活的地方，其宫廷区域分为用于政务办公的外廷和帝室生活的内廷两个部分，建筑风格东西合璧。1945年满洲国解体以后，帝宫建筑毁损严重。<br />\r\n1962年在满洲国帝宫旧址上成立伪皇宫陈列馆，1964年与吉林省博物馆合署办公，1982年恢复建制，1984年正式对外开放。2000年7月1日划归长春市管理，2001年2月8日改名为伪满皇宫博物院；现已全面整修，基本恢复旧貌。2013年，中华人民共和国国务院将之以伪满皇宫及日伪军政机构旧址之名列入第七批全国重点文物保护单位（近现代重要史迹及代表性建筑）。<br />\r\n2017年，伪满皇宫博物院被中国博物馆协会评为第三批国家一级博物馆。</p>\r\n\r\n<p><img alt=\"\" src=\"/static/uploads/ckeditor/201803241309567f4e4bffb6f04a8498ff137b9a3558d6.jpg\" style=\"height:498px; width:750px\" /></p>\r\n', '吉林省长春市宽城区光复北路5号', '1', '1', '2', '2018-03-24 13:10:08');

-- ----------------------------
-- Table structure for suggestion
-- ----------------------------
DROP TABLE IF EXISTS `suggestion`;
CREATE TABLE `suggestion` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `content` text,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `ix_suggestion_addtime` (`addtime`)
) ENGINE=MyISAM AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of suggestion
-- ----------------------------
INSERT INTO `suggestion` VALUES ('1', 'andy', 'andy@qq.com', 'haha', '2018-03-22 14:56:05');
INSERT INTO `suggestion` VALUES ('2', 'andy', 'andy@qq.com', 'haha', '2018-03-22 14:58:57');
INSERT INTO `suggestion` VALUES ('3', 'andy', 'andy@qq.com', 'haha', '2018-03-22 14:59:55');
INSERT INTO `suggestion` VALUES ('4', 'andy', 'andy@qq.com', 'haha', '2018-03-22 14:59:59');
INSERT INTO `suggestion` VALUES ('5', 'andy', 'andy@qq.com', 'haha', '2018-03-22 15:00:03');
INSERT INTO `suggestion` VALUES ('6', 'andy', 'andy@qq.com', 'haha', '2018-03-22 15:00:43');
INSERT INTO `suggestion` VALUES ('7', 'andy', 'andy@qq.com', 'haha', '2018-03-22 15:00:48');
INSERT INTO `suggestion` VALUES ('8', 'andy', 'andy@qq.com', 'haha', '2018-03-22 15:01:12');
INSERT INTO `suggestion` VALUES ('10', 'andy', 'andy@qq.com', 'haha', '2018-03-22 15:21:12');
INSERT INTO `suggestion` VALUES ('11', '明日科技粉丝', 'funs@qq.com', '我是明日科技的忠实粉丝，希望你们出更多的精品图书！', '2018-03-22 15:22:25');

-- ----------------------------
-- Table structure for travels
-- ----------------------------
DROP TABLE IF EXISTS `travels`;
CREATE TABLE `travels` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(255) DEFAULT NULL,
  `author` varchar(255) DEFAULT NULL,
  `content` text,
  `scenic_id` int(11) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `title` (`title`),
  KEY `ix_travels_addtime` (`addtime`),
  KEY `scenic_id` (`scenic_id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of travels
-- ----------------------------
INSERT INTO `travels` VALUES ('1', '北京不得不去的地方——故宫一日游', '老冯', '<p>【关于门票】<br />\r\n故宫门票价格：成人旺季60元，淡季40元，学生票全年20元。珍宝馆和钟表馆另外收费10元/人，学生证半价。<br />\r\n我们去的时候故宫还可以现场售票，回来以后就实行全网络售票参观了。<br />\r\n门票提前10天在网上预售，售完为止，一张身份证每个入院日限购一张门票。和其它博物馆一样，故宫博物院也是周一闭馆。<br />\r\n去之前建议关注一下故宫博物院的官网：http://gugong.228.com.cn/，尤其是跟我们一样自由行的游客，除了可以看到余票和购买门票，还能看到最新的一些消息公告，比如哪里闭馆哪里修缮（虽然有些宫殿临时维修不在官网通告，但有总好过无嘛），对规划路线有很大的帮助。<br />\r\n我们是在美团上提前买的大门票和珍宝馆的门票，刷身份证就可以入园。<br />\r\n【没什么用的讲解器】<br />\r\n过了安检就能看到讲解器服务处。<br />\r\n自助讲解器租赁价格：汉语、粤语、闽南语版20.00元/台，其他语种40.00元/台，免押金，参观完毕在出院前将讲解器归还即可。<br />\r\n我和泡泡一人租了一台，使用下来的感受是缺点多过优点，可以不租。<br />\r\n虽说它是自动感应的，走到哪里讲到哪里，讲解的内容也挺不错，有多个版本，我们听的是王刚老师讲的故事版，生动有趣。但是它的缺点也很明显。<br />\r\n1、因为是单耳佩戴，所以在环境嘈杂的地方，即使声音开的很大，也经常听不清楚说了什么。<br />\r\n2、走到一些建筑密集的地方，讲解器会错乱崩溃。比如我们在珍妃井附近转了很久，它始终就识别不到我们所在的位置。比如我们到了宁寿宫，它却讲的是皇极殿的内容。泡泡一度以为是不是讲解器坏了，还跑到服务处换了一个，工作人员倒是很耿直，说这个就是这样的，不是很灵，到了不放他们也没办法。因为是自动定位讲解，又不能选择自己想听的地方，所以就导致我们很多地方到最后也没能听到讲解。<br />\r\n3、所有内容只讲一次，如果你没听得清，或者中途不小心耳机掉下来，漏听了，也只能自认倒霉。<br />\r\n其实故宫只要不闭馆，根本不可能有人少的时候，一个又一个旅行团，你想不听导游的讲解都很难。当然，这只是我们的看法，讲解器本身不贵，想要的话也可以租一个备用，权当地图用也行。<br />\r\n我和泡泡在故宫走了一整天。从早上的人头攒动待到晚上的人去楼空。<br />\r\n很多人说故宫没意思，就是看看长的差不多的房子。我倒觉得这一趟来的超值。<br />\r\n我建议对历史，尤其是明清史感兴趣的亲们，可以多预留一些时间给这座紫禁城，它会还你无限惊喜。</p>\r\n\r\n<p>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;<img alt=\"\" class=\"left\" src=\"/static/uploads/ckeditor/2018032411373051faede1c35748c7b2347dc0c6397e29.png\" style=\"height:296px; width:660px\" /></p>\r\n', '1', '2018-03-22 13:49:32');
INSERT INTO `travels` VALUES ('2', '最轻松愉快的方式游览故宫', 'Andy', '<p>午门是紫禁城的正门，也是今天故宫博物院的正门。位于紫禁城乃至京师南北轴线，始建于明朝永乐十八年（1420年）。平面呈巨大的&ldquo;凹&rdquo;字形，中间广场面积超过9900平方米。在阳光普照的日子走到这里，如果看不到两遍雁翅楼的阴影，便是午门最亮丽的时候，也就是它的名字&mdash;&mdash;正午之门，充分显示它的阳刚之气。<br />\r\n<br />\r\n午门门楼连台通高近37.9米，正中的主楼属重庑殿顶（五脊四面坡），面阔九间（60.05米），进深五间（25米），亦为最尊贵的九五之数。按&ldquo;九&rdquo;为数理中阳数之极，&ldquo;五&rdquo;居阳数之中（王者之数），可见午门在位置上的重要性。<br />\r\n<br />\r\n午门面向正南，五行属火，是积极的红色。不只红墙，檐下彩绘也以红色为主，显示光明正大。按传统四灵兽的方位（东青龙，西白虎，南朱雀，北玄武），南方既以朱雀（凤凰）为象征，午门由5座楼阁组成，高低错落，左右翼然，形若大鸟展翅，故又称五凤楼。<br />\r\n<br />\r\n城楼立面大小形制与天安门相若，但没有像天安门那样五门相列，并采取&ldquo;中开三门&rdquo;，正中门卫皇帝专用御道，只有皇后在大婚时，可以乘坐喜轿从大清门中经过进宫一次。另外通过殿试选拔的状元、榜眼、探花可从中门出宫一次。东侧门供文武官员出入，西侧门供宗师王公出入。（撰文：《紫禁城100》）<br />\r\n<br />\r\n关于午门的以讹传讹<br />\r\n电视剧里经常能听到&ldquo;推出午门斩首&rdquo;这样的圣令，但是午门真的是用来处决死刑犯的吗？其实不尽然。午门主要的用途有三：其一朝廷每年冬天会在午门举行隆重的颁朔仪式（也就是颁布日历）；其二战争凯旋后，会在午门前广场举行受俘仪式，彰显大国威仪；其三廷杖触怒皇帝的大臣。廷杖通俗地说就是用棍子打屁股的一种刑罚。有趣的是主事廷杖的太监会根据收取贿赂与否，喊出&ldquo;着实打&rdquo;和&ldquo;用心打&rdquo;，&ldquo;着实打&rdquo;或者苟活，&ldquo;用心打&rdquo;必遭打死。</p>\r\n\r\n<p><img alt=\"\" src=\"/static/uploads/ckeditor/2018032413245286a7d302f4654833bf1873e40249ce63.png\" style=\"height:305px; width:656px\" /></p>\r\n', '1', '2018-03-24 13:24:56');

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pwd` varchar(100) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  `face` varchar(255) DEFAULT NULL,
  `info` text,
  `phone` varchar(11) DEFAULT NULL,
  `username` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`),
  UNIQUE KEY `phone` (`phone`),
  UNIQUE KEY `face` (`face`),
  KEY `ix_user_addtime` (`addtime`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('4', 'pbkdf2:sha256:50000$TkExX9Jm$d63477853a17dcaedcd52be4b6213ebb74b61a12456762ac19d6b7dfb559aa57', 'andy@mrsoft.com', '2018-03-23 14:26:12', null, null, null, 'Andy');
INSERT INTO `user` VALUES ('5', 'pbkdf2:sha256:50000$qFfVpeJK$9bc7ff46019ff211c31081e016d42770be6fae4df99e2f8d386ebd00e852ebda', 'zhangsan@qq.com', '2018-08-10 10:50:34', null, null, null, '张三');
INSERT INTO `user` VALUES ('7', 'pbkdf2:sha256:50000$sSujvFmg$0958ae9e146e41e1301d38c55d424fe9c1fae98c0843e84234fefe1aab1a7d38', 'lisi@qq.com', '2018-08-10 16:10:13', null, null, null, '李四');

-- ----------------------------
-- Table structure for userlog
-- ----------------------------
DROP TABLE IF EXISTS `userlog`;
CREATE TABLE `userlog` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) DEFAULT NULL,
  `ip` varchar(100) DEFAULT NULL,
  `addtime` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `ix_userlog_addtime` (`addtime`),
  KEY `user_id` (`user_id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of userlog
-- ----------------------------
INSERT INTO `userlog` VALUES ('1', '1', '127.0.0.1', '2018-03-23 10:06:15');
INSERT INTO `userlog` VALUES ('2', '4', '127.0.0.1', '2018-03-23 14:28:54');
INSERT INTO `userlog` VALUES ('3', '5', '127.0.0.1', '2018-08-10 10:50:56');
INSERT INTO `userlog` VALUES ('4', '7', '127.0.0.1', '2018-08-11 09:12:38');
INSERT INTO `userlog` VALUES ('5', '7', '127.0.0.1', '2018-08-11 09:21:02');
INSERT INTO `userlog` VALUES ('6', '7', '127.0.0.1', '2018-08-13 09:24:59');
INSERT INTO `userlog` VALUES ('7', '5', '127.0.0.1', '2018-08-13 09:33:05');
INSERT INTO `userlog` VALUES ('8', '5', '127.0.0.1', '2018-08-13 10:35:49');
