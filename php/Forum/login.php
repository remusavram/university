<?php
	session_start();
	
	include("connect.php");
	include("functii.php");
	
	if(isset($_SESSION['user_id']))
	{
		header('Location:index.php');
	}
	
	$error= array();
	if(isset($_POST['submitform']))
	{
		
		//username
		if(empty($_POST['username']))
		{
			$error[] = 'Introduceti usernameul ! ';
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
		
		if(empty($error))
		{
			$rez_user = mysql_query("SELECT * FROM user WHERE username='$username' AND password='$password' ") or die (mysql_error());
			if (mysql_num_rows($rez_user)==1)
			{
				while($rand_user = mysql_fetch_array($rez_user))
				{
					$_SESSION['id_user'] =  $rand_user['id_user'];								
					header('Location:index.php');
				}
			}
			else
		   	{
		   		$error[] =' ID sau parola nevalide. Va rugam sa incercati din nou! ' ; 
		   	}		
		}
		       
       	if(!empty($error)) 
       	{
			$error_message ='<span class="error">' ;
			foreach($error as $cheie=>$valuare) 
			{	
				$error_message.= "$valuare";
			}
			$error_message.="</span> <br/><br/>";
		}
	}
?>

<html lang="en">
<head>
	<title>Log In</title>
	<link rel="stylesheet" href="css/main.css">
	<link rel="stylesheet" href="css/forms.css">
</head>
<body>
	<div id="page">
	<header id="header">
			<div id="dreaptasus"><?php headerCode(); ?></div>
	</header><br/>
		<section id="login">
			<form id="formular" method="post" action="">
				<h3>Log In</h3>
				<?php if (isset($error_message)){ echo $error_message;}?>
				<div class="field">
					<label for="username">Username:</label>
					<input type="text" class="input" id="username" name="username" maxlength="20" required />
				</div>
				<div class="field">
					<label for="password">Password:</label>
					<input type="password" class="input" id="password" name="password" maxlength="20" required />
				</div><br/> 
		
				<input type="submit" class="button" name="submitform" id="submit" value="Log In" />
				<a href="index.php"><input type="button" class="button" name="cancelsubmit" id="cancelsubmit" value="Cancel" /></a>
				<a href="inregistrare.php"><input type="button" class="button" name="newaccount" id="newaccount" value="NEW Account" /></a>
			</form>
		</section>
	<footer id="footer">
			<?php footerCode(); ?>
	</footer>
	</div>
</body>
<html> 