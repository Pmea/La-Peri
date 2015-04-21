	$(document).ready(function(){
		var temperatures = [25,21,18,17,16,15,14,13,12];
		var humidites = [10,13,15,18,18,21,23,40,45];
	
		var plot1 = $.jqplot ('chart1', [humidites, temperatures], 
		{
			title:'Deux Derniers Jours',
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
				}
			}
		});
	});
