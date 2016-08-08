-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Gazda: 127.0.0.1
-- Timp de generare: 23 Mar 2013 la 12:49
-- Versiune server: 5.5.27
-- Versiune PHP: 5.4.7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Baza de date: `temaphp`
--

-- --------------------------------------------------------

--
-- Structura de tabel pentru tabelul `comentarii`
--

CREATE TABLE IF NOT EXISTS `comentarii` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `continut` longtext NOT NULL,
  `data` datetime NOT NULL,
  `id_stire` int(11) NOT NULL,
  `id_autor` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  UNIQUE KEY `id` (`id`),
  KEY `id_2` (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Salvarea datelor din tabel `comentarii`
--

INSERT INTO `comentarii` (`id`, `continut`, `data`, `id_stire`, `id_autor`, `status`) VALUES
(1, 'Acesta este  comentariu 1 pentru stirea nr. 1', '2013-03-23 03:05:13', 1, 1, 1),
(2, 'Acesta este  comentariu 2 pentru stirea nr. 1', '2013-03-23 01:03:03', 1, 1, 1),
(3, 'sagsagas', '2013-03-23 09:27:12', 1, 1, 1),
(4, '', '2013-03-23 09:27:50', 1, 1, 0),
(5, 'sdgdsgsd', '2013-03-23 09:41:55', 1, 1, 0),
(6, 'sagasgsasa sg', '2013-03-23 09:42:07', 1, 1, 1),
(7, 'iiii', '2013-03-23 12:26:03', 4, 1, 1),
(8, 'yui', '2013-03-23 12:31:02', 5, 9, 1),
(9, 'kkkkkkk', '2013-03-23 12:31:32', 4, 9, 1),
(10, 'dgdsgsdgsdgds', '2013-03-23 12:45:20', 5, 1, 1);

-- --------------------------------------------------------

--
-- Structura de tabel pentru tabelul `stire`
--

CREATE TABLE IF NOT EXISTS `stire` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `continut` varchar(250) NOT NULL,
  `detalii` longtext NOT NULL,
  `data` datetime NOT NULL,
  `id_user` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Salvarea datelor din tabel `stire`
--

INSERT INTO `stire` (`id`, `continut`, `detalii`, `data`, `id_user`) VALUES
(1, 'Stire nr. 1', 'Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol Acesta este continutul primului articol v Acesta este continutul primului articol Acesta este continutul primului articolAcesta este continutul primului articol Acesta este continutul primului articol', '2013-03-23 00:00:00', 1),
(2, 'Stire nr. 2', ' Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2  Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2  Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2  Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2  Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2  Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2  Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 Continutul stiri cu numarul 2 ', '2013-03-23 00:00:00', 1),
(4, 'test articol 3', 'continut text articol 3 continut text articol 3 continut text articol 3 continut text articol 3 continut text articol 3 continut text articol 3 continut text articol 3 ', '2013-03-23 10:43:29', 8),
(5, '66666', 'kkk', '2013-03-23 12:29:41', 9);

-- --------------------------------------------------------

--
-- Structura de tabel pentru tabelul `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(25) NOT NULL,
  `password` varchar(32) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Salvarea datelor din tabel `user`
--

INSERT INTO `user` (`id`, `username`, `password`) VALUES
(1, 'andrei.ciungulete', '098f6bcd4621d373cade4e832627b4f6'),
(8, 'dan', '9180b4da3f0c7e80975fad685f7f134e'),
(9, 'rtt', '735b90b4568125ed6c3f678819b6e058');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
