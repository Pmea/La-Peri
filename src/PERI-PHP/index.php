<!DOCTYPE html>
<html>
	<head>
	<meta name="description" content="Bienvenue sur le site de météorologique des SARs" />
	<meta charset="utf-8" />
	<link rel="stylesheet" href="css/style.css" />
	<title>Site météorologique</title>
	
		
	<script src="js/jquery-1.11.2.min.js"></script>	
	<script type="text/javascript" src="js/jqPlot/jquery.jqplot.min.js"></script>	
    <script type="text/javascript" src="js/jqPlot/plugins/jqplot.canvasTextRenderer.min.js"></script>
	<script type="text/javascript" src="js/jqPlot/plugins/jqplot.canvasAxisLabelRenderer.min.js"></script>	
    <script src="js/loadData.js"></script>
	</head>
	
	<body>
		<?php include("loadGraphe.php") ?>
		<section id="meteo">
			<h1>Station Méteo</h1>
		
			<section id="station">
				<p id="lum"></p>
				<img id="img_lum"/>
				<p id="heure"></p>
				<p id="temp"></p>
				<p id="hum"></p><img id="goutte" width="32px" height="32px" src="img/goutte.jpg"/>
				
			</section>
			
			<section id="recap">
			<div id="chart1" style="height:500px; width:600px;"></div>
			</section>
		</section>
	</body>
</html>