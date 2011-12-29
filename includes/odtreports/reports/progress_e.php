<?php

/**
 * Tutoriel file
 * Description : Merging a Segment within an array
 * You need PHP 5.2 at least
 * You need Zip Extension or PclZip library
 *
 * @copyright  GPL License 2008 - Julien Pauli - Cyril PIERRE de GEYER - Anaska (http://www.anaska.com)
 * @license    http://www.gnu.org/copyleft/gpl.html  GPL License
 * @version 1.3
 */


// Make sure you have Zip extension or PclZip library loaded
// First : include the librairy
require_once('../library/odf.php');

$odf = new odf("progress_e.odt");

$odf->setVars('school', 'Lanna International School Thailand');

$reportname = "Progress Report Card";

$odf->setVars('reportname', $reportname);

$listeArticles = array(
  array(  'course' => 'PHP',
//      'texte' => '',
  ),
  array(  'course' => 'MySQL',
//      'texte' => 'MySQL est un système de gestion de base de données (SGDB). Selon le (...)',
  ),
  array(  'course' => 'Apache',
//      'texte' => 'Apache HTTP Server, souvent appelé Apache, est un logiciel de serveur (...)',
  ),
  array(  'course' => '.NET',
//      'texte' => '',
  ),
);

$article = $odf->setSegment('articles');
foreach($listeArticles AS $element) {
  $article->courseArticle($element['course']);
//  $article->texteArticle($element['texte']);
  $article->merge();
}
$odf->mergeSegment($article);

// We export the file
$odf->exportAsAttachedFile('Progress_ee.odt');

?>