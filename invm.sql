-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.6.23-log - MySQL Community Server (GPL)
-- Server OS:                    Win32
-- HeidiSQL Version:             9.1.0.4867
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Dumping database structure for zues_inventory_management
CREATE DATABASE IF NOT EXISTS `zues_inventory_management` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `zues_inventory_management`;


-- Dumping structure for table zues_inventory_management.business
CREATE TABLE IF NOT EXISTS `business` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL DEFAULT '0',
  `email` varchar(50) NOT NULL DEFAULT '0',
  `address` varchar(150) NOT NULL DEFAULT '0',
  `contact` varchar(50) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- Dumping data for table zues_inventory_management.business: ~2 rows (approximately)
/*!40000 ALTER TABLE `business` DISABLE KEYS */;
INSERT INTO `business` (`id`, `name`, `email`, `address`, `contact`) VALUES
	(1, 'b1', 'email1', 'add1', '1234'),
	(2, 'b2', 'email2', 'add2', '123456'),
	(3, 'b3', 'email3', 'add3', '12345'),
	(4, 'xxx', 'xxxx', 'xxxxx', '1234');
/*!40000 ALTER TABLE `business` ENABLE KEYS */;


-- Dumping structure for table zues_inventory_management.company
CREATE TABLE IF NOT EXISTS `company` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL DEFAULT '0',
  `address` varchar(150) DEFAULT '0',
  `phone` varchar(50) DEFAULT '0',
  `email` varchar(50) DEFAULT '0',
  `website` varchar(50) DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- Dumping data for table zues_inventory_management.company: ~2 rows (approximately)
/*!40000 ALTER TABLE `company` DISABLE KEYS */;
INSERT INTO `company` (`id`, `name`, `address`, `phone`, `email`, `website`) VALUES
	(1, 'company_133', '', '', '', 'www.'),
	(2, 'ddddddd', '', '', '', 'www.');
/*!40000 ALTER TABLE `company` ENABLE KEYS */;


-- Dumping structure for table zues_inventory_management.customer
CREATE TABLE IF NOT EXISTS `customer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL DEFAULT '0',
  `address` varchar(50) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- Dumping data for table zues_inventory_management.customer: ~0 rows (approximately)
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` (`id`, `name`, `address`) VALUES
	(1, 'customer_1', 'address_1');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;


-- Dumping structure for table zues_inventory_management.inventory
CREATE TABLE IF NOT EXISTS `inventory` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `item_id` int(11) NOT NULL DEFAULT '0',
  `vendor_id` int(11) NOT NULL DEFAULT '0',
  `cost` int(11) NOT NULL DEFAULT '0',
  `delivery_receipt_no` int(11) NOT NULL DEFAULT '0',
  `purchase_date` date NOT NULL,
  `quantity` int(11) NOT NULL DEFAULT '0',
  `batch_no` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table zues_inventory_management.inventory: ~0 rows (approximately)
/*!40000 ALTER TABLE `inventory` DISABLE KEYS */;
/*!40000 ALTER TABLE `inventory` ENABLE KEYS */;


-- Dumping structure for table zues_inventory_management.item
CREATE TABLE IF NOT EXISTS `item` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL DEFAULT '0',
  `code` int(11) NOT NULL DEFAULT '0',
  `reorder_level` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `code` (`code`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- Dumping data for table zues_inventory_management.item: ~2 rows (approximately)
/*!40000 ALTER TABLE `item` DISABLE KEYS */;
INSERT INTO `item` (`id`, `name`, `code`, `reorder_level`) VALUES
	(1, 'item_1', 1234, 0),
	(2, 'testitem', 1001, 1);
/*!40000 ALTER TABLE `item` ENABLE KEYS */;


-- Dumping structure for table zues_inventory_management.vendor
CREATE TABLE IF NOT EXISTS `vendor` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) NOT NULL DEFAULT '0',
  `address` varchar(50) DEFAULT NULL,
  `zip` varchar(50) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  `phone` varchar(50) DEFAULT NULL,
  `website` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- Dumping data for table zues_inventory_management.vendor: ~0 rows (approximately)
/*!40000 ALTER TABLE `vendor` DISABLE KEYS */;
INSERT INTO `vendor` (`id`, `name`, `address`, `zip`, `email`, `phone`, `website`) VALUES
	(11, 'qw', '', '', '', '', 'www.');
/*!40000 ALTER TABLE `vendor` ENABLE KEYS */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
