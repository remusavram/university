<?php
session_start();
include("connect.php");
include("functii.php");

?>

<!DOCTYPE html>
<html lang="en">
<head>
	<title>Comentarii</title>
	<link rel="stylesheet" href="css/main.css">
	<link rel="stylesheet" href="css/comentariu.css">
</head>
<body>
	<div id="page"> 
	<header id="header">
			<div id="dreaptasus"><?php headerCode(); ?></div>
	</header><br/>
	<h2>Parerea Ta Conteaza !</h2><br/>
	
	<section id="stiri">
			<?php afisareStireComentarii(); ?>
	</section>
	
	<section id="listacomentari">
			<?php afisareComentarii(); ?>
			<?php adaugaButoaneComentariu(); ?>
	</section>
	
	<footer id="footer">
	</footer>
	</div>
</body>
</html>
