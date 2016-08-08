<?php
session_start();
include("connect.php");
include("functii.php");

//redirectare automata catre index.php daca utilizatorul nu este logat.
if(isset($_SESSION['id_user']))	
{ 
	$id_user=$_SESSION['id_user']; 
}
else {header('Location:index.php');}

if(isset($_POST['submit']))
{
	$error = array();
	$id_stire = $_GET['x'];

	//continut comentariu
	if(empty($_POST['continut'])){
		$error[] = 'Introduceti un comentariu ! ';
	}else { 
		$continut = $_POST['continut'];
	}

	if(empty($error))
	{    
		$status='0'; // comentariu nevizibil --> default 
		$rez_insertie = mysql_query("INSERT INTO comentariu (id_comentariu,continut,data,id_stire,id_user,status) 
				                     VALUES ('','$continut',now(),'$id_stire','$id_user','$status') ") or die(mysql_error());
		$redirect='Location:comentariu.php?x='.$id_stire;
		
			if($rez_insertie) {header($redirect); } //redirectare catre comentarii.
			else { $error[] =' NU S-A PUTUT ADAUGA COMENTARIU ! '; }
	}
	
	if(!empty($error)) {
		$error_message = '<span class="error">';
		foreach ($error as $cheie => $valuare)
		{ $error_message.="$valuare"; }
		$error_message.='</span><br/><br/>';
	}
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
	<title>Adauga Comentariu</title>
	<link rel="stylesheet" href="css/main.css">
</head>
<body>
	<div id="page"> 
	<header id="header">
			<div id="dreaptasus"><?php headerCode(); ?></div>
	</header><br/>
		<section id="adaugastire">
			<form class="formular2" method="post" action="">
				<h3>Adauga Comentariu</h3> <br />
				<?php if (isset($error_message)){ echo $error_message;}?>
				<div class="field">
					<label for="continut">Continut Comentariu :</label>
					 <textarea id="continut" name="continut" rows="5" cols="80" required></textarea>			
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
