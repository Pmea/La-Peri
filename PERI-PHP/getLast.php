	<?php 
		include("gestionFile.php"); 
		/* Recuperer le derniere timestamp dans le fichier XML */
		echo getLastValue("xml/fichier.xml");
	?>