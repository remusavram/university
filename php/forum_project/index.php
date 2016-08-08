<?php
session_start();
include("connect.php");
include("functii.php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<title>Home Page</title>
	<link rel="stylesheet" href="css/main.css">
	<link rel="stylesheet" href="css/stire.css">
</head>
<body>
	<div id="page"> 
	<header id="header">
			<div id="dreaptasus"><?php headerCode(); ?></div>
	</header><br/>
	<h2>Stiri</h2><br/>
	
	<section id="listastiri">
			<?php afisareStiri(); ?>
			<div id="adugabuton"><?php adaugaButonStire(); ?></div>
	</section>
	
	<footer id="footer">
	<?php footerCode()?>
	</footer>
	</div>
</body>
</html>