<?php

function afisareStiri()
{
	$query=mysql_query("SELECT user.username,stire.continut,stire.data,stire.id_stire 
			            FROM user JOIN stire  
			            ON user.id_user=stire.id_user 
			            ORDER BY stire.data") 	or die (mysql_error());
		
	if (mysql_num_rows($query)!=0)
	{
		$count=1;
		while($stire = mysql_fetch_array($query))
		{
			$x=$stire['id_stire'];
			echo '<div id="stire"><div id="continut"><a href="comentariu.php?x='.$x.'">
					'.$count.'.  '.$stire['continut'].'</a></div><br/>'.
					'<div id="data"> data : '.$stire['data'].'</div>'.
					'<div id="utilizator"> stire postata de : <strong>'.$stire['username'].'</strong></div><br/>
				  </div>';
			$count++;
		}
	}
	else 
	{ 
		echo ' NU EXISTA STIRI POSTATE ' ; 
	}
}


function adaugaButonStire()
{
	if(isset($_SESSION['id_user']))
	{
		echo '<a href="adaugastire.php">
				<input type="button" name="adaugaButonStire" id="adaugaButonStire" class="button" value="ADAUGA STIRE"/>
			  </a>';
	}
}


function afisareStireComentarii()
{
	$x = $_GET['x'];
	$query=mysql_query("SELECT user.username,stire.continut,stire.detaliu,stire.data
			            FROM user JOIN stire
			            ON user.id_user=stire.id_user
			            WHERE stire.id_stire='$x' ") or die (mysql_error());

	if (mysql_num_rows($query)!=0)
	{
		while($stire = mysql_fetch_array($query))
		{
			echo '<div id="stire">
					<div id="continut_stire">'.$stire['continut'].'</div><br/>'
					.'<div id="detaliu_stire">'.$stire['detaliu'].'</div><br/>'
					.'<div id="data_stire"> data : '.$stire['data'].'</div><br/>'
					.'<div id="utilizator_stire"> stire postata de : <strong>'.$stire['username'].'</strong></div><br/>
				  </div>';
		}
	}
	else 
	{
		echo ' NU EXISTA STIRI POSTATE ' ; 
	}
}


function afisareComentarii()
{
	$x = $_GET['x'];
	//returneaza id-ul userului care a postat stirea 	
	$query_user = mysql_query("SELECT stire.id_user
			                   FROM user
			                   JOIN comentariu ON user.id_user = comentariu.id_user
			                   JOIN stire ON comentariu.id_stire = stire.id_stire
			                   WHERE stire.id_stire = '$x' ")  or die (mysql_error());
	
	//returneaza comentariile valide (au statusul 1)
	$query_comentarii_valide = mysql_query("SELECT user.username, comentariu.continut, comentariu.data
					                         FROM user
					                         JOIN comentariu ON user.id_user = comentariu.id_user
					                         JOIN stire ON comentariu.id_stire = stire.id_stire
					                         WHERE stire.id_stire = '$x' AND comentariu.status = '1'
					                         ORDER BY comentariu.data")  or die (mysql_error());
	
	//returneaza toate comentariile valide si invalide		
	$query_toate_comentariile = mysql_query("SELECT user.username, comentariu.continut, comentariu.data, comentariu.id_comentariu, comentariu.status
					                         FROM user
					                         JOIN comentariu ON user.id_user = comentariu.id_user
					                         JOIN stire ON comentariu.id_stire = stire.id_stire
					                         WHERE stire.id_stire = '$x'
					                         ORDER BY comentariu.data")  or die (mysql_error());

	
	if(isset($_SESSION['id_user'])) // daca userul este logat
	{
	    $id_user=$_SESSION['id_user'];
	    $stire = mysql_fetch_array($query_user);
	    $stire_user=$stire['id_user'];
		    				    				
		if($id_user==$stire_user)// daca userul logat este acelasi care a postat stirea
		{
			while($comentariu = mysql_fetch_array($query_toate_comentariile))
			{
				 $i=$comentariu['id_comentariu']; 
				 echo '<div id="comentariu">
				          <div id="continut_comentariu">'.$comentariu['continut'].'</div><br/>'
						 .'<div id="data_comentariu"> data : '.$comentariu['data'].'</div><br/>'
						 .'<div id="utilizator_comentariu"> comentariu postat de : <strong>'.$comentariu['username'].'</strong></div><br/>			
						   <form name="val" id="val" method="POST" action="">';
		 		if($comentariu['status']==1)
		 		{
					echo '<label>NEVALID</label><input type="radio" name="validare'.$i.'" id="no" value="no">
							<label>VALID</label><input type="radio" name="validare'.$i.'" id="yes" value="yes" checked>';
		 		}
		 		else if($comentariu['status']==0)
		 		{
					  echo '<label>NEVALID</label><input type="radio" name="validare'.$i.'" id="no" value="no" checked>
					  		<label>VALID</label><input type="radio" name="validare'.$i.'" id="yes" value="yes" >';
				}						                     		 
				echo '<input type="submit" name="validareButon'.$i.'" class="button" value="Submit"/>
			          </form>
					   </div><br>';
				//validare comentarii
				$validareButon='validareButon'.$i;
				$validare='validare'.$i;
				if(isset($_POST[$validareButon]))
				{ 
	           		//daca se solicita schimbarea statusului comentariului
	               	$optiune_validare = $_POST[$validare];
	               	if ($optiune_validare == 'yes')
	               	{
	               		$val = mysql_query(" UPDATE comentariu SET status='1' WHERE id_comentariu='$i'") or die(mysql_error());
	              		if($val)
	              		{
	                     	header('Location: comentariu.php?x='.$x.'');			                            			                            			
	                    } 
	              	}
	               	else if ($optiune_validare == 'no')
	               	{
	               		$neval = mysql_query(" UPDATE comentariu SET status='0' WHERE id_comentariu='$i'") or die(mysql_error());
	              		if($neval)
	               		{
		                   	header('Location: comentariu.php?x='.$x.'');			                            			
		                }
		           	}
				}
		 	}				 	
		}
		//afisare comenatrii valide pentru utilizatorii care nu au postat stirea
		else
		{			
			while($comentariu = mysql_fetch_array($query_comentarii_valide))
			{
		 		echo '<div id="comentariu">
	    	  			<div id="continut_comentariu">'.$comentariu['continut'].'</div><br/>'
						.'<div id="data_comentariu"> data : '.$comentariu['data'].'</div><br/>'
			    		.'<div id="utilizator_comentariu"> comentariu postat de : <strong>'.$comentariu['username'].'</strong></div><br/>
	           			</div>';
			}
		}

	//afisare comentarii valide pentru utilizatorii neautentificati
	}
	else
	{
		while($comentariu = mysql_fetch_array($query_comentarii_valide))
		{
			echo '<div id="comentariu">
		          <div id="continut_comentariu">'.$comentariu['continut'].'</div><br/>'
			    .'<div id="data_comentariu"> data : '.$comentariu['data'].'</div><br/>'
				.'<div id="utilizator_comentariu"> comentariu postat de : <strong>'.$comentariu['username'].'</strong></div><br/>
		         </div>';
		}
	}
}


function adaugaButoaneComentariu()
{
	if(isset($_SESSION['id_user']))
	{
		$x = $_GET['x'];
		echo '<a href="adaugacomentariu.php?x='.$x.'">
				<input type="button" name="adaugaButonComentariu" id="adaugaButonComentariu" class="button" value="Adauga Comentariu"/>
			  </a>
			  <a href="index.php"><input type="button" name="butonCancel" id="butonCancel" class="button" value="Cancel"/></a>';
	}
}


function headerCode()
{
	if(isset($_SESSION['id_user'])) 
	{ 
		$id_user=$_SESSION['id_user'];
		$query = mysql_query("SELECT username FROM user WHERE id_user='$id_user' ") or die (mysql_error());
		if($query) 
		{ 
			$user_logat = mysql_fetch_array($query); 
		}
		echo '<strong>'.$user_logat['username'].'</strong> | <a href="index.php">HOME</a> | <a href="logout.php">Log Out</a>';
	}
	else 
	{
		echo '<a href="login.php">Log In</a> | <a href="inregistrare.php">Inregistrare</a> | <a href="index.php">HOME</a> ';
	}
}


function footerCode()
{
	echo ' Made by Remus Avram';
}
?>