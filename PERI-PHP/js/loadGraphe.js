    google.load('visualization', '1.1', {packages: ['line']});
    google.setOnLoadCallback(drawChart);

    function drawChart() {

      var data = new google.visualization.DataTable();
      data.addColumn('string', 'Jour');	  
      data.addColumn('number', 'Humidité');
      data.addColumn('number', 'Temperature');

	  /* A traiter */
      data.addRows([
        ["Lundi",  37.8, 20.8],
        ["Mardi",  30.9, 18.5],
        ["Mercredi",  25.4,   25],
        ["Jeudi",  11.7, 18.8],
        ["Vendredi",  11.9, 17.6],
        ["Samedi",   8.8, 13.6],
		["Dimanche",   8.8, 13.6]
      ]);

      var options = {
        chart: {
          title: 'Météo de la semaine'
        },
        width: 650,
        height: 500
      };

      var chart = new google.charts.Line(document.getElementById('chart_div'));

      chart.draw(data, options);
    }