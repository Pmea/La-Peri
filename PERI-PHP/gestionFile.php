<?php

function getAllValues($path){
	$xml = simplexml_load_file($path);
	$tab = '';
	for($i = 0; $i < sizeof($xml); $i++){
		$last = $xml->timestamp[$i];
		$res = $last['valeur'].' '.$last->temperature.' '.$last->humidite.' '.$last->luminosite;
		$tab = $tab . " " . $res;
	}
	return $tab;
}

/* Recupere la valeur a du timestamp a l'indice "indice" */
function getValue($path, $indice){
	$xml = simplexml_load_file($path);
	
	if($indice >= sizeof($xml))
		return null;
	
	$last = $xml->timestamp[$indice];
	
	return $last['valeur'].' '.$last->temperature.' '.$last->humidite.' '.$last->luminosite;
}

/* Recupere la valeur a du dernier timestamp */
function getLastValue($path){
	$xml = simplexml_load_file($path);
	$taille = sizeof($xml);
	
	$last = $xml->timestamp[$taille-1];
	
	return $last['valeur'].' '.$last->temperature.' '.$last->humidite.' '.$last->luminosite;
}

?>