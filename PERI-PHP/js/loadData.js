
/* Demarre la loop et l'execute toute les 1 seconde */
/* Appel AJAX et mise a jour du HTML avec les données reçues */

$(document).ready( 

function loop() {

	var now = new Date();
	var heure   = ('0'+now.getHours()  ).slice(-2);
	var minute  = ('0'+now.getMinutes()).slice(-2);

	setTimeout(function(){
		$.ajax({
			type   : 'GET',
			url    : 'getLast.php',
			success: function(msg) {
				var tab = msg.split(' ');
				
				traitementLumino(tab[3], tab[2], heure);
				$("#heure").html(heure+":"+minute);				
				$("#temp").html(tab[1]+" °c");
				$("#hum").html(tab[2]+"%");
			}
		});
		loop();
}, 1000);

});

function traitementLumino(val, hum, heure){
	if(hum > 50){
		/* Pluie */	
		$("#img_lum").attr("src", "img/pluie.jpg");	
	}else if(heure < 7 || heure > 21){
		/* Nuit */
		$("#img_lum").attr("src", "img/lune.jpg");
	}else if(val > 50){
		/* Soleil */	
		$("#img_lum").attr("src", "img/soleil.jpg");
	}else if(val > 25){
		/* Nuage */	
		$("#img_lum").attr("src", "img/nuage_beau.jpg");
	}else{
		/* Gris */	
		$("#img_lum").attr("src", "img/nuage.jpg");
	}

}