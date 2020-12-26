/*
Navicat MySQL Data Transfer

Source Server         : ckgl
Source Server Version : 50717
Source Host           : localhost:3306
Source Database       : ckgl

Target Server Type    : MYSQL
Target Server Version : 50717
File Encoding         : 65001

Date: 2020-06-12 08:20:12
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `glyb`
-- ----------------------------
DROP TABLE IF EXISTS `glyb`;
CREATE TABLE `glyb` (
  `gno` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '管理员编号',
  `gpass` varchar(10) COLLATE utf8_bin NOT NULL COMMENT '管理员密码',
  `gname` char(10) COLLATE utf8_bin NOT NULL COMMENT '管理员姓名',
  `gsex` char(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '管理员性别',
  `gtele` varchar(100) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '管理员手机号'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ----------------------------
-- Records of glyb
-- ----------------------------
INSERT INTO `glyb` VALUES ('001', '123', '张三', '男', '13988884444');
INSERT INTO `glyb` VALUES ('002', '456', '李四', '男', '12345678912');
INSERT INTO `glyb` VALUES ('003', '789', '菲菲', '女', '159354795362');
INSERT INTO `glyb` VALUES ('004', '111', '王明', '男', '183654795123');
INSERT INTO `glyb` VALUES ('005', '222', '小红', '女', '18366664444');
INSERT INTO `glyb` VALUES ('006', '654', '李林', '男', '17858459652');
INSERT INTO `glyb` VALUES ('007', '987', '唐风', '男', '13566663333');
INSERT INTO `glyb` VALUES ('008', '333', '李勇', '男', '14595643216');
INSERT INTO `glyb` VALUES ('009', '555', '团团', '女', '13245698745');
INSERT INTO `glyb` VALUES ('010', '666', '高雯', '女', '151367942563');
INSERT INTO `glyb` VALUES ('1111', '1111', '53', '男', '15965475322');

-- ----------------------------
-- Table structure for `hpb`
-- ----------------------------
DROP TABLE IF EXISTS `hpb`;
CREATE TABLE `hpb` (
  `hno` char(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品编号',
  `hname` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品名称',
  `hdw` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品单位',
  `hsort` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品分类',
  `hfact` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品公司',
  `hdate` varchar(20) CHARACTER SET latin1 DEFAULT NULL COMMENT '货品日期'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ----------------------------
-- Records of hpb
-- ----------------------------
INSERT INTO `hpb` VALUES ('DA001', '冰箱', '台', '家电', '新飞电器集团有限公司', '2020/6/1');
INSERT INTO `hpb` VALUES ('DA002', '冰箱', '台', '家电', '海尔电器集团有限公司', '2020/4/6');
INSERT INTO `hpb` VALUES ('DA003', '冰箱', '台', '家电', '容声电器集团有限公司', '2020/4/6');
INSERT INTO `hpb` VALUES ('DB001', '彩电', '台', '家电', '海尔电器集团有限公司', '2020/5/1');
INSERT INTO `hpb` VALUES ('DB002', '彩电', '台', '家电', '长虹电器集团有限公司', '2020/3/4');
INSERT INTO `hpb` VALUES ('DB001', '洗衣机', '台', '家电', '海尔电器集团有限公司', '2020/3/25');
INSERT INTO `hpb` VALUES ('SA001', '洗衣粉', '袋', '日用品', '上海东园公司', '2020/5/14');
INSERT INTO `hpb` VALUES ('SA002', '热水瓶', '个', '日用品', '天津海河公司', '2020/5/46');
INSERT INTO `hpb` VALUES ('SB001', '马桶', '个', '日用品', '上海苏比司洗具公司', '202/5/25');

-- ----------------------------
-- Table structure for `jckb`
-- ----------------------------
DROP TABLE IF EXISTS `jckb`;
CREATE TABLE `jckb` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `hno` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品编号',
  `gno` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '管理员编号',
  `hp_num` char(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品数量',
  `hp_price` int(10) NOT NULL COMMENT '货品价格',
  `hp_date` date NOT NULL COMMENT '货品日期',
  `hp_sort` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品分类',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ----------------------------
-- Records of jckb
-- ----------------------------
INSERT INTO `jckb` VALUES ('1', 'DA001', '001', '-2', '1800', '2020-03-01', '出库');
INSERT INTO `jckb` VALUES ('2', 'DA002', '001', '-2', '1400', '2020-03-01', '出库');
INSERT INTO `jckb` VALUES ('3', 'DA003', '001', '-2', '1000', '2020-03-01', '出库');
INSERT INTO `jckb` VALUES ('4', 'DB001', '001', '-3', '1400', '2020-03-01', '出库');
INSERT INTO `jckb` VALUES ('5', 'DB002', '001', '-3', '800', '2020-03-01', '出库');
INSERT INTO `jckb` VALUES ('6', 'DA001', '001', '2', '1300', '2020-02-25', '入库');
INSERT INTO `jckb` VALUES ('7', 'DA002', '001', '2', '1000', '2020-02-25', '入库');
INSERT INTO `jckb` VALUES ('8', 'DA003', '001', '2', '600', '2020-02-25', '入库');
INSERT INTO `jckb` VALUES ('9', 'DB001', '001', '3', '1000', '2020-02-25', '入库');
INSERT INTO `jckb` VALUES ('10', 'DB002', '001', '3', '500', '2020-02-25', '入库');
INSERT INTO `jckb` VALUES ('11', 'DA001', '001', '12', '1000', '2020-05-29', '入库');
INSERT INTO `jckb` VALUES ('12', 'DA002', '001', '12', '1000', '2020-05-29', '入库');
INSERT INTO `jckb` VALUES ('13', 'DA003', '003', '10', '1500', '2020-05-29', '入库');
INSERT INTO `jckb` VALUES ('14', 'DA002', '003', '100', '600', '2020-05-29', '入库');
INSERT INTO `jckb` VALUES ('15', 'DA002', '001', '100', '1000', '2020-06-05', '入库');
INSERT INTO `jckb` VALUES ('16', 'DA002', '001', '-5', '1500', '2020-06-05', '出库');
INSERT INTO `jckb` VALUES ('17', 'DA003', '002', '15', '1000', '2020-06-05', '入库');
INSERT INTO `jckb` VALUES ('18', 'DB002', '005', '100', '500', '2020-06-09', '入库');
INSERT INTO `jckb` VALUES ('19', 'DA002', '001', '-50', '1500', '2020-06-09', '出库');
INSERT INTO `jckb` VALUES ('20', 'DA001', '001', '10', '1000', '2020-06-09', '入库');
INSERT INTO `jckb` VALUES ('21', 'DA001', '001', '-10', '2000', '2020-06-09', '出库');
INSERT INTO `jckb` VALUES ('22', 'DA003', '001', '10', '1000', '2020-06-09', '入库');
INSERT INTO `jckb` VALUES ('23', 'DA003', '001', '10', '1000', '2020-06-09', '入库');

-- ----------------------------
-- Table structure for `jckb1`
-- ----------------------------
DROP TABLE IF EXISTS `jckb1`;
CREATE TABLE `jckb1` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `hno` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品编号',
  `gno` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '管理员编号',
  `hp_num` char(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品数量',
  `hp_price` int(10) NOT NULL COMMENT '货品价格',
  `hp_date` date NOT NULL COMMENT '货品日期',
  `hp_sort` varchar(10) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '货品分类',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=114 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- ----------------------------
-- Records of jckb1
-- ----------------------------
INSERT INTO `jckb1` VALUES ('91', 'DA001', '001', '-2', '1800', '2020-03-01', '出库');
INSERT INTO `jckb1` VALUES ('92', 'DA002', '001', '-2', '1400', '2020-03-01', '出库');
INSERT INTO `jckb1` VALUES ('93', 'DA003', '001', '-2', '1000', '2020-03-01', '出库');
INSERT INTO `jckb1` VALUES ('94', 'DB001', '001', '-3', '1400', '2020-03-01', '出库');
INSERT INTO `jckb1` VALUES ('95', 'DB002', '001', '-3', '800', '2020-03-01', '出库');
INSERT INTO `jckb1` VALUES ('96', 'DA001', '001', '2', '1300', '2020-02-25', '入库');
INSERT INTO `jckb1` VALUES ('97', 'DA002', '001', '2', '1000', '2020-02-25', '入库');
INSERT INTO `jckb1` VALUES ('98', 'DA003', '001', '2', '600', '2020-02-25', '入库');
INSERT INTO `jckb1` VALUES ('99', 'DB001', '001', '3', '1000', '2020-02-25', '入库');
INSERT INTO `jckb1` VALUES ('100', 'DB002', '001', '3', '500', '2020-02-25', '入库');
INSERT INTO `jckb1` VALUES ('101', 'DA001', '001', '12', '1000', '2020-05-29', '入库');
INSERT INTO `jckb1` VALUES ('102', 'DA002', '001', '12', '1000', '2020-05-29', '入库');
INSERT INTO `jckb1` VALUES ('103', 'DA003', '003', '10', '1500', '2020-05-29', '入库');
INSERT INTO `jckb1` VALUES ('104', 'DA002', '003', '100', '600', '2020-05-29', '入库');
INSERT INTO `jckb1` VALUES ('105', 'DA002', '001', '100', '1000', '2020-06-05', '入库');
INSERT INTO `jckb1` VALUES ('106', 'DA002', '001', '-5', '1500', '2020-06-05', '出库');
INSERT INTO `jckb1` VALUES ('107', 'DA003', '002', '15', '1000', '2020-06-05', '入库');
INSERT INTO `jckb1` VALUES ('108', 'DB002', '005', '100', '500', '2020-06-09', '入库');
INSERT INTO `jckb1` VALUES ('109', 'DA002', '001', '-50', '1500', '2020-06-09', '出库');
INSERT INTO `jckb1` VALUES ('110', 'DA001', '001', '10', '1000', '2020-06-09', '入库');
INSERT INTO `jckb1` VALUES ('111', 'DA001', '001', '-10', '2000', '2020-06-09', '出库');
INSERT INTO `jckb1` VALUES ('112', 'DA003', '001', '10', '1000', '2020-06-09', '入库');
INSERT INTO `jckb1` VALUES ('113', 'DA003', '001', '10', '1000', '2020-06-09', '入库');
