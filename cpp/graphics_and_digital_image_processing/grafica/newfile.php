<html >
<head >
<h1 style="background-color:Gray; text-align:center;"> Tema PHP</h1>
</head>
<body style="background-color:#500000;">
<form action="newfile.php" method="post">
A11: <input type="text" name="a11" value="1"/>
</br>
A12: <input type="text" name="a12" value="1"/>
</br>
A13: <input type="text" name="a13" value="1"/>
</br>
A21: <input type="text" name="a21" value="1"/>
</br>
A22: <input type="text" name="a22" value="1"/>
</br>
A23: <input type="text" name="a23" value="1"/>
</br>
A31: <input type="text" name="a31" value="1"/>
</br>
A32: <input type="text" name="a32" value="1"/>
</br>
A33: <input type="text" name="a33" value="1"/>
</br>
<input type="submit" value="OK"/>
</form>


<?php
$matrice=array(array($_POST["a11"],$_POST["a12"],$_POST["a13"]),
			array($_POST["a21"],$_POST["a22"],$_POST["a23"]),
			array($_POST["a31"],$_POST["a32"],$_POST["a33"]));
$cost=array(array(0,9999,9999),
	array(9999,9999,9999),
	array(9999,9999,9999)
);
$prec=array(array(-1,9999,9999),
	array(9999,9999,9999),
	array(9999,9999,9999)
);

$visit=array(array(1,0,0),
array(0,0,0),
array(0,0,0)
);

$qi=array();
$qj=array();
array_push($qi, 0);
array_push($qj, 0);  	
while(empty($qi) == false)
{
	$vi=$qi[0];
	$vj=$qj[0];
	array_shift($qi);
	array_shift($qj);
	$dri=$vi;
	$drj=$vj+1;
	$josi=$vi+1;
	$josj=$vj;
	if($drj<3)
	{
		if($cost[$vi][$vj]+$matrice[$vi][$vj]<$cost[$dri][$drj])
		{
			$cost[$dri][$drj]=$cost[$vi][$vj]+$matrice[$vi][$vj];
			$prec[$dri][$drj]=($vi*3+$vj);
		}
		if($visit[$dri][$drj]==0)
		{
			array_push($qi, $dri);
			array_push($qj, $drj);
			$visit[$dri][$drj]=1;
		}
	}	
	if($josi<3)
	{
		if($cost[$vi][$vj]+$matrice[$vi][$vj]<$cost[$josi][$josj])
		{
			$cost[$josi][$josj]=$cost[$vi][$vj]+$matrice[$vi][$vj];
			$prec[$josi][$josj]=$vi*3+$vj;
		}
		if($visit[$josi][$josj]==0)
		{
			array_push($qi, $josi);
			array_push($qj, $josj);
			$visit[$josi][$josj]=1;
		}
	}	
}
for($i=0;$i<3; $i++)
{
	for($j=0;$j<3;$j++)
		echo $cost[$i][$j]." ";
	echo "</br>";
}

echo "Suma minima este:".($cost[2][2]+$matrice[2][2])."<br/>";
$qsi=array();
$qsj=array();
$i=2;
$j=2;
while ($prec[$i][$j]!=-1)
{
	array_push($qsi, $i);
	array_push($qsj, $j);
	$iv=$i;
	$i=floor($prec[$i][$j]/3);
	$j=($prec[$iv][$j]%3);
	
}
array_push($qsi, 0);
array_push($qsj, 0);
echo "</br>Drumul minim este:";
While(empty($qsi)==false)
{
	echo "(".array_pop($qsi).", ".array_pop($qsj).")";
}
?>
</body>
</html>