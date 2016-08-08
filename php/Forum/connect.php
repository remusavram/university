<?php

$server='localhost';
$username='root';
$password='';
$database='db';

$connect_server = mysql_connect($server,$username,$password);

// se verifica conexiunea la server
if(!$connect_server) 
{
	die('Conexiunea la server NEREUSITA !');
}

$connect_database = mysql_select_db($database,$connect_server);

// se verifica conexiunea la baza de date
if(!$connect_database) 
{
	die('Conexiunea la baza de date NEREUSITA !');
}
 
?>