-- phpMyAdmin SQL Dump
-- version 4.0.4.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Sep 11, 2013 at 10:12 AM
-- Server version: 5.6.11
-- PHP Version: 5.5.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `db`
--
CREATE DATABASE IF NOT EXISTS `db` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `db`;

-- --------------------------------------------------------

--
-- Table structure for table `comentarii`
--

CREATE TABLE IF NOT EXISTS `comentarii` (
  `id_comentariu` int(11) NOT NULL AUTO_INCREMENT,
  `continut` longtext NOT NULL,
  `data` datetime NOT NULL,
  `id_stire` int(11) NOT NULL,
  `id_autor` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  PRIMARY KEY (`id_comentariu`),
  UNIQUE KEY `id_comentariu` (`id_comentariu`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `stire`
--

CREATE TABLE IF NOT EXISTS `stire` (
  `id_stire` int(11) NOT NULL AUTO_INCREMENT,
  `continut` varchar(250) NOT NULL,
  `detalii` longtext NOT NULL,
  `data` datetime NOT NULL,
  `id_user` int(11) NOT NULL,
  PRIMARY KEY (`id_stire`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(25) NOT NULL,
  `password` varchar(32) NOT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
