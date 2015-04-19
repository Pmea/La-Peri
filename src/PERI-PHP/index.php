<!DOCTYPE html>
<html>
	<head>
	<meta name="description" content="Bienvenue sur le site de météorologique des SARs" />
	<meta charset="utf-8" />
	<link rel="stylesheet" href="css/style.css" />
	<title>Site météorologique</title>
	
		
    <!-- <script type="text/javascript" src="js/jsapi.js"></script> -->
	<script src="js/jquery-1.11.2.min.js"></script>
    <script src="js/loadData.js"></script>
	<script src="js/loadGraphe.js"></script>
	</head>
	
	<body>

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
			<div id="chart_div"></div>
			</section>
		</section>
	</body>
</html>