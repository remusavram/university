-- phpMyAdmin SQL Dump
-- version 4.0.4.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Sep 11, 2013 at 10:53 AM
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
-- Table structure for table `comentariu`
--

CREATE TABLE IF NOT EXISTS `comentariu` (
  `id_comentariu` int(11) NOT NULL AUTO_INCREMENT,
  `continut` longtext NOT NULL,
  `data` datetime NOT NULL,
  `id_stire` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `status` int(11) NOT NULL,
  PRIMARY KEY (`id_comentariu`),
  UNIQUE KEY `id_comentariu` (`id_comentariu`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `comentariu`
--

INSERT INTO `comentariu` (`id_comentariu`, `continut`, `data`, `id_stire`, `id_user`, `status`) VALUES
(1, 'O adevarata tragedie!', '2013-09-11 11:23:14', 1, 1, 1),
(2, 'Afectata a fost si zona Fukushima, unde 2.821 de oameni au murit in timpul evacuarii din zona centralei nucleare avariate. Intr-o mai mica masura au fost afectate prefecturile Ibaraki, Chiba, Kanagawa, Tokyo, Tochigi. ', '2013-09-11 11:25:50', 1, 2, 0),
(3, 'Crapaturi, praf si termene la limita. ', '2013-09-11 11:32:28', 3, 3, 0);

-- --------------------------------------------------------

--
-- Table structure for table `stire`
--

CREATE TABLE IF NOT EXISTS `stire` (
  `id_stire` int(11) NOT NULL AUTO_INCREMENT,
  `continut` varchar(250) NOT NULL,
  `detaliu` longtext NOT NULL,
  `data` datetime NOT NULL,
  `id_user` int(11) NOT NULL,
  PRIMARY KEY (`id_stire`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `stire`
--

INSERT INTO `stire` (`id_stire`, `continut`, `detaliu`, `data`, `id_user`) VALUES
(1, 'Japonia: La doi ani &#351;i jum&#259;tate dup&#259; tsunami, 2.654 de cadavre nu au fost înc&#259; recuperate', 'La exact doi ani &#351;i jum&#259;tate dup&#259; seismul &#351;i valul tsunami de la 11 martie 2011 din nord-estul Japoniei, 2.654 de cadavre nu au putut fi înc&#259; recuperate dintr-un total de 18.537 de mor&#355;i, potrivit celor mai recente date ale poli&#355;iei na&#355;ionale, preluate de France Presse, relateaz&#259; Agerpres.\r\n\r\nJaponia, greu încercat&#259;. FOTOREPORTAJ cople&#351;itor din mijlocul seismului care a lovit &#355;ara în 2011\r\n\r\nValul devastator care a înghi&#355;it peste 500 de kilometri din coastele de est &#351;i nord ale Japoniei a luat totul cu el la trecerea sa, iar numeroase cadavre au ajuns în Oceanul Pacific. Cu toate acestea, opera&#355;iuni de c&#259;utare continu&#259;, fie chiar &#351;i pentru a le mai oferi crâmpeie de speran&#355;&#259; familiilor victimelor.\r\nCel mai grav bilan&#355; uman al acestui cutremur cu magnitudinea de 9 grade urmat de un tsunami &#351;i numeroase replici puternice a fost înregistrat în prefectura Miyagi, cu 10.834 de mor&#355;i (dintre care 1.297 de cadavre înc&#259; nerecuperate).\r\n\r\nSeismul cu magnitudinea 9 pe Richter, produs în Japonia, a deplasat axa de rota&#355;ie a P&#259;mântului cu aproape 10 centimetri, a anun&#355;at Institutul de Geofizic&#259; din Italia.', '2013-09-11 11:19:11', 1),
(2, 'E-mailul trimis de unul din cei mai puternici oameni din SUA imediat dup&#259; ATENTATE: "Sfâr&#351;itul se apropie. Asist&#259;m la NOUA ORDINE MONDIAL&#258;"', 'America este &#355;ara tuturor posibilit&#259;&#355;ilor, a libert&#259;&#355;ii &#351;i a visurilor împlinite. Dar tot de aici vin teorii ale conspira&#355;iei care se r&#259;spândesc cu repeziciune în întreaga lume.\r\nCine a provocat atentatele de la 11 Septembrie? Cine conduce de fapt America? Ce se ascunde în spatele celor mai controversate legi adoptate de Congres? sunt doat câteva subiecte care ridic&#259; semne de întrebare &#351;i atrag aten&#355;ia oamenilor.\r\n\r\nStew Webb, un "cercet&#259;tor" în domeniul conspira&#355;iilor pretinde c&#259; a primit de la familia Rockefeller un email trimis prin intermediul Rockefeller Global Communications.\r\nNu se &#351;tiu circumstan&#355;ele prin care acest e-mail a ajuns în posesia lui Stew, dar lucrurile descrise în el pun într-o alt&#259; lumin&#259; evenimentele petrecute.\r\n\r\nIat&#259; câteva rânduri din scrisoare:\r\nFrom: “Rockefeller Global Communications” <admin@rockefeller.com.au>\r\nTo: <stewwebb@*****.net>\r\nDate: Thu, 21 Mar 2002 20:27:55 +1000\r\nSubject: The Countdown to Armageddon (Numerotarea invers&#259; pân&#259; la Armagedon)\r\n\r\nPentru marea umanitate,\r\n\r\nTimpul sfâr&#351;itului se apropie. C&#259; v&#259; place sau nu, to&#355;i trebuie s&#259; ne înfrunt&#259;m destinul. Pe 11 septembrie 2001, lumea a fost martora începutului sfâr&#351;itului. Ceea ce am v&#259;zut &#351;i am experimentat nu va fi nimic fa&#355;&#259; de dezastrul care urmeaz&#259; s&#259; vin&#259;. \r\n(...)Noul Sistem se apropie. Singura întrebare e urm&#259;toarea: ve&#355;i alege s&#259; fi&#355;i acolo sau ve&#355;i continua pe calea distrugerii? Depinde doar de voi. Agenda este inevitabil&#259; &#351;i va trebui s&#259; îndura&#355;i pentru a ajunge acolo. A&#351;a c&#259; gândi&#355;i-v&#259; profund.\r\n\r\nE viitorul vostru. &#350;i poate ve&#355;i face bine cu to&#355;ii.', '2013-09-11 11:27:40', 2),
(3, 'Autostrada SUSPINELOR. Nu se circul&#259; pe ea, dar gropile sunt deja în asfalt, iar alunec&#259;rile de teren fac imposibil&#259; inaugurarea', 'Cr&#259;p&#259;turi, praf &#351;i termene la limit&#259;. A&#351;a arata autostrada Sibiu-Or&#259;&#351;tie din elicopter. Sibienii ar putea circula totu&#351;i pân&#259; la finalul acestui an pe autostrad&#259; pân&#259; la Or&#259;&#351;tie pe  trei dintre cele patru tronsoane de autostad&#259; sus&#355;ine site-ul turnulsfatului.ro.\r\n\r\nÎn imaginile surprinse din aer se poate observa c&#259; pe tronsonul trei au ap&#259;rut noi alunec&#259;ri de teren, iar termenele pentru terminarea lucr&#259;rilor au fost prelungite.\r\n\r\nAutostrada Sibiu-Or&#259;&#351;tie trebuia s&#259; fie gata în luna aprilie a acestui an, îns&#259; termenele au fost prelungite a&#351;a c&#259; ar putea fi gata abia la anul.', '2013-09-11 11:30:12', 2),
(4, '11 septembrie: cel mai norocos supravie&#355;uitor al atacurilor teroriste î&#351;i spune pentru prima oar&#259; povestea\r\n', 'Timp de 12 ani, a refuzat s&#259; vorbeasc&#259; despre cum a fentat moartea de dou&#259; ori în ziua în care aproape 3.000 de persoane au murit, iar alte 8.900 au fost r&#259;nite. Din respect pentru familiile colegilor care au murit. Acum, Steve Sullivan, membru al unui echipaj de pompieri care a intervenit la turnurile gemene imediat dup&#259; ce au fost lovite de avioanele deturnate de terori&#351;ti, descrie circumstan&#355;ele extraordinare c&#259;rora le datoreaz&#259; via&#355;a.\r\n\r\nAtunci când a fost f&#259;cut&#259; fotografia de mai sus, nimeni nu &#351;tia c&#259; aceasta a surprins, de fapt, un miracol. Înc&#259; un pompier murdar &#351;i extenuat, înconjurat de r&#259;m&#259;&#351;i&#355;ele cl&#259;dirilor care, pân&#259; în urm&#259; cu câteva ore, erau printre cele mai înalte din lume. Îns&#259; Steve Sullivan, pompierul murdar &#351;i extenuat din aceast&#259; fotografie, trebuia s&#259; fie mort, dup&#259; cum spune chiar el. „Înc&#259; nu pot crede ceea ce s-a întâmplat în acea zi. N-am vorbit niciodat&#259; despre asta în public. În&#355;eleg pe deplin cât de norocos am fost. Sunt atât de recunosc&#259;tor”, poveste&#351;te el pentru prima dat&#259; într-o discu&#355;ie cu jurnali&#351;tii publica&#355;iei britanice „Mirror”.\r\n', '2013-09-11 11:31:22', 3);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(25) NOT NULL,
  `password` varchar(32) NOT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id_user`, `username`, `password`) VALUES
(1, 'remus', '123'),
(2, 'florin', '123'),
(3, 'daniel', '123');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
