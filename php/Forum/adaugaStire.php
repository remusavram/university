<?php

session_start();
include("connect.php");
include("functii.php");

//redirectare automata catre index.php daca utilizatorul nu este logat.
if(isset($_SESSION['id_user']))	
{ 
	$id_user=$_SESSION['id_user']; 
}
else 
{
	header('Location:index.php');
}

if(isset($_POST['submit']))
{
	$error = array();

	//continut stire
	if(empty($_POST['continut']))
	{
		$error[] = 'Introduceti un titlu ! ';
	}
	else 
	{ 
		$continut = $_POST['continut'];
	}

	//detalii stire
	if(empty($_POST['detaliu']))
	{
		$error[] = ' Introduceti continutul stirii ! ';
	}
	else
	{
		$detaliu = $_POST['detaliu'];
	}
	
	//daca nu sunt errori...
	if(empty($error))
	{    
		$rez_insertie = mysql_query("INSERT INTO stire (id_stire,continut,detaliu,data,id_user) 
				                     VALUES ('','$continut','$detaliu',now(),'$id_user') ") or die(mysql_error());
		
		if($rez_insertie) 
		{ 
			header('Location:index.php');
		}
		else 
		{
			$error[] =' NU S-A PUTUT ADAUGA STIREA ! ';
		}
	}
	
	//daca sunt errori...afiseazale
	if(!empty($error)) 
	{
		$error_message = '<span class="error">';
		foreach ($error as $cheie => $valuare)
		{ 
			$error_message.="$valuare"; 
		}
		$error_message.='</span><br/><br/>';
	}
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
	<title>Adauga Stire</title>
	<link rel="stylesheet" href="css/main.css">
</head>
<body>
	<div id="page"> 
	<header id="header">
			<div id="dreaptasus"><?php headerCode(); ?></div>
	</header><br/>
		<section id="adaugastire">
			<form class="formular2" method="post" action="">
				<h3>Adauga Stire</h3> <br />
				<?php if (isset($error_message)){ echo $error_message;}?>
				<div class="field">
					<label for="continut">Continut :</label>
					 <textarea id="continut" name="continut" rows="2" cols="80" required></textarea>			
				</div>				
				<div class="field">
					<label for="detaliu">Detaliu :</label>
					<textarea id="detaliu" name="detaliu" rows="10" cols="80" required></textarea>								
				</div>
				<br/><br/>
				<input type="submit" name="submit" id="submit" class="button" value="Submit"/>
				<a href="index.php"><input type="button" class="button" name="cancelsubmit" id="cancelsubmit" value="Cancel" /></a>	
			</form>
		</section>
	<footer id="footer">
			<?php footerCode(); ?>
	</footer>
	</div>
</body>
</html>
