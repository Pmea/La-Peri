 <?php 
	include("gestionFile.php"); 
	/* Recuperer les timestamp dans le fichier XML */
	$tab = getAllValues("xml/fichier.xml");

	return php2js($tab);
?>