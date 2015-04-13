
/* Demarre la loop et l'execute toute les 1 seconde */
/* Appel AJAX et mise a jour du HTML avec les données reçues */

$(document).ready( 

function loop() {

	setTimeout(function(){
		$.ajax({
			type   : 'GET',
			url    : 'getLast.php',
			success: function(msg) {
				var tab = msg.split(' ');
						
				$("#temp").html("Température: "+tab[1]);
				$("#hum").html("Humidité: "+tab[2]);
				$("#lum").html("Luminosité: "+tab[3]);
			}
		});
		loop();
}, 1000);
});