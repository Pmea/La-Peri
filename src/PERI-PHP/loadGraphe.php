 <?php 
	include("gestionFile.php"); 
	/* Recuperer les timestamp dans le fichier XML */
	$res = getAllValues("xml/fichier.xml");
	$tabjs = php2js($res);
?>
<script language="JavaScript">
	$(document).ready(function(){
		var tab =<?php echo $tabjs; ?>;
	  	
	  	/*Traitement du tableau de retour*/

		var temperatures = [];
		var humidites = [];
		var tmp;

		for (var i = tab.length - 1; i >= 0; i--) {
			tmp = tab[i].split(" ");
			temperatures.push(tmp[1]);
			humidites.push(tmp[2]);
		};

		var plot1 = $.jqplot ('chart1', [temperatures, humidites], 
		{
			title:'Trois Derniers Jours',
			height: 500,
			width: 600,
			series: [
				{
					yaxis: 'yaxis',
					showMarker:false
				},
				{
					yaxis: 'y2axis',
					showMarker:false
				}
			],
			axes:{
				y2axis:{
					min:0,
					max:100,
					tickInterval: 25
				},	
				yaxis:{
					min:-15,
					max:60,
					tickInterval: 5
				}	
			}
		});
	});
</script>
