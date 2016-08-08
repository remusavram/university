<!doctype html>
<html lang="en">
<head>
	<meta charset="utf-8" />
	<title>Hybrid Cars</title>
	<link rel="stylesheet" href="styles.css" type="text/css" media="screen" />
	<link rel="stylesheet" type="text/css" href="print.css" media="print" />
	<!--[if IE]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->


</head >
<body>
<div id="wrapper"><!-- #wrapper -->

	<nav><!-- top nav -->
		<div class="menu">
			<ul>
				<li><a href="index.html">Home</a></li>
				<li><a href="HybridElectricCars.html">Hybrid Electric Cars</a></li>
				<li><a href="gallery.html">Hybrid Cars Gallery</a></li>
				<li><a href="3Dview.html">Car 3D View</a></li>
				<li><a href="AboutUs.html">About Us</a></li>
				<li><a href="ContactUs.html">Contact Us</a></li>
			</ul>
		</div>
	</nav><!-- end of top nav -->
	
	<header><!-- header -->
		<h1><a href="index.html">Hybrid Cars</a></h1>
		<h2>All about hybrid cars</h2>
	</header><!-- end of header -->
	
	<section id="main"><!-- #main content and sidebar area -->
			<section id="content"><!-- #content -->
			
        		<article>
						<h2>Calendar</h2>
				<?php
  $monthNames = Array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");
	if (!isset($_REQUEST["month"])) $_REQUEST["month"] = date("n");
	if (!isset($_REQUEST["year"]))  $_REQUEST["year"]  = date("Y");
	
  $cMonth = $_REQUEST["month"];
  $cYear  = $_REQUEST["year"];
                
  $prev_year = $cYear;
  $next_year = $cYear;

 	$prev_month = $cMonth-1;
 	$next_month = $cMonth+1;

 	if ($prev_month == 0 ) {
    $prev_month = 12;
    $prev_year = $cYear - 1;
  }
 	if ($next_month == 13 ) {
    $next_month = 1;
    $next_year = $cYear + 1;
  }
?>
   <div id="calendar_div" name="calendar_div">
    <table width="200">
        <tr align="center">
          <td bgcolor="#999999" style="color:#FFFFFF">
            	<table width="100%" border="0" cellspacing="0" cellpadding="0">
                    <tr>
                      <td width="50%" align="left">&nbsp;&nbsp;<a href="<?php echo $_SERVER["PHP_SELF"] . "?month=". $prev_month . "&year=" . $prev_year; ?>" style="color:#FFFFFF">Previous</a></td>
                      <td width="50%" align="right"><a href="<?php echo $_SERVER["PHP_SELF"] . "?month=". $next_month . "&year=" . $next_year; ?>" style="color:#FFFFFF">Next</a>&nbsp;&nbsp;</td>
                    </tr>
              </table>
          </td>
        </tr>
        <tr>
            <td align="center">
              <table width="100%" border="0" cellpadding="2" cellspacing="2">
                <tr align="center">
                  <td colspan="7" bgcolor="#999999" style="color:#FFFFFF"><strong><?php echo $monthNames[$cMonth-1].' '.$cYear; ?></strong></td>
                </tr>
                <tr>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>S</strong></td>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>M</strong></td>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>T</strong></td>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>W</strong></td>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>T</strong></td>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>F</strong></td>
                  <td align="center" bgcolor="#999999" style="color:#FFFFFF"><strong>S</strong></td>
                </tr>

                <?php 
                	$timestamp = mktime(0,0,0,$cMonth,1,$cYear);
                	$maxday    = date("t",$timestamp);
                	$thismonth = getdate ($timestamp);
                	$startday  = $thismonth['wday'];

                  for ($i=0; $i<($maxday+$startday); $i++) {
                    if(($i % 7) == 0 ) echo "<tr>\n";
                    if($i < $startday) echo "<td></td>\n";
                    else echo "<td align='center' valign='middle' height='20px'>". ($i - $startday + 1) . "</td>\n";
                    if(($i % 7) == 6 ) echo "</tr>\n";
                  }  
                 ?>
              </table>
            </td>
        </tr>
    </table>
</div>
				</article>
						
			</section><!-- end of #content -->

		<aside id="sidebar"><!-- sidebar -->
				<h3>Hybrid Car Links</h3>
					<ul>
						<li><a href="WhatAreHyb.html">What are Hybrid Cars</a></li>
						<li><a href="ProCon.html">Hybrid Car Pros & Cons</a></li>
						<li><a href="HowWork.html">How Hybrid Cars Work</a></li>
						<li><a href="HistoryHybrid.html">History of Hybrid Vehicles</a></li>
						<li><a href="FutureHybrid.html">Future Hybrid Cars</a></li>
						<li><a href="AdvantageHybrid.html">Advantages of Hybrid Cars</a></li>
						<li><a href="DisadvantagesHybrid.html">Disadvantages Of Hybrid Cars</a></li>
					</ul>
				<h3>Top 5 Hybrid Cars</h3>
				
				<script type="text/javascript">
				if (window.XMLHttpRequest)
				{
					xmlhttp=new XMLHttpRequest();
				}
				else
				{
					xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
				}
				xmlhttp.open("GET","xml/top5.xml",false);
				xmlhttp.send();
				xmlDoc=xmlhttp.responseXML; 

				document.write("<ol>");
				var x = xmlDoc.getElementsByTagName("piece");
				for(i=0;i<=x.length-1;i++){
					document.write("<li>");
					document.write(x[i].getElementsByTagName("car")[0].childNodes[0].nodeValue);
					document.write("</li>");
	
				}
				document.write("</ol>");

				</script>
			
		<h3><a href="calendarP.php">Calendar</a></h3>
		
					
		</aside><!-- end of sidebar -->

	</section><!-- end of #main content and sidebar-->
	
		<footer>
		<section id="footer-area">

			<section id="footer-outer-block">
					
					<aside class="footer-segment">
							<h4>All rights reserved</h4>
								<p><a href="index.html">HybridCarSite.com</a>&copy; 2012 </p>
					</aside>
			</section><!-- end of footer-outer-block -->

		</section><!-- end of footer-area -->
	</footer>
	
</div><!-- #wrapper -->

</body>
</html>
