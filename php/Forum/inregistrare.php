<?php
session_start();
include("connect.php");
include("functii.php");

if(isset($_POST['submit']))
{
	$error = array();

	//username
	if(empty($_POST['username']))
	{
		$error[] = 'Introduceti username-ul ! ';
	}
	else 
	{ 
		$username = $_POST['username'];
	}

	//password
	if(empty($_POST['password']))
	{
		$error[] = ' Introduceti parola ! ';
	}
	else
	{
		$password = $_POST['password'];
	}

	//reintroducere password
	if(empty($_POST['repassword']))
	{
		$error[] = ' Reintroduceti parola ! ';
	}
	else
	{
		$repassword = $_POST['repassword'];
	}

	if($password != $repassword) 
	{
		$error[]=' Parola reintrodusa gresit ! ';
	}

	if(empty($error))
	{   
		// verifica unicitatea username-ului si a parolei introduse //
		$rez_unicitate = mysql_query(" SELECT * FROM user WHERE username='$username' ") or die(mysql_error());
		
		//daca interogarea asupra bazei de date returneza 0 randuri //
		if(mysql_num_rows($rez_unicitate)==0) 			
		{
			$rez_insertie = mysql_query("INSERT INTO user (id_user,username,password) VALUES ('','$username','$password') ") or die(mysql_error());
			if($rez_insertie) 
			{ 
				header('Location:login.php');
			}
			else 
			{ 
				$error[] =' Reintroduceti datele de inregistrare ! '; 
			}
		}
		else 
		{ 
			$error[] =' Usernameul introdus nu este disponibil . ';
		}
	}
	
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
	<title>Inregistrare User</title>
	<link rel="stylesheet" href="css/main.css">
	<link rel="stylesheet" href="css/forms.css">
</head>
<body>
	<div id="page"> 
	<header id="header">
			<div id="dreaptasus"><?php headerCode(); ?></div>
	</header><br/>
		<section id="inregistare">
			<form id="formular" method="post" action="">
				<h3>Inregistrare User</h3> <br />
				<?php if (isset($error_message)){ echo $error_message;}?>
				<div class="field">
					<label for="username">Username:</label>
					<input type="text" class="input" id="username" name="username"  maxlength="20" required/>					
				</div>				
				<div class="field">
					<label for="password">Password:</label>
					<input type="password" class="input" id="password" name="password" maxlength="20" required/>					
				</div>
				<div class="field">
					<label for="repassword">Retype Password:</label>
					<input type="password" class="input" id="repassword" name="repassword" maxlength="20" required/>
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
