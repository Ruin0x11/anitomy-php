--TEST--
anitomy_parse() Basic test
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$ret = anitomy_parse("[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv");

var_dump($ret);

$ret = anitomy_parse("[shirt] Pokemon Master Journeys S24E01 - To Train or Not to Train! (Teletoon)");

var_dump($ret);
?>
--EXPECT--
array(8) {
  ["file_extension"]=>
  string(3) "mkv"
  ["file_name"]=>
  string(58) "[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)]"
  ["video_resolution"]=>
  string(8) "1280x720"
  ["video_term"]=>
  string(4) "x264"
  ["audio_term"]=>
  string(3) "AAC"
  ["episode_number"]=>
  string(2) "06"
  ["anime_title"]=>
  string(11) "Psycho-Pass"
  ["release_group"]=>
  string(8) "Kamigami"
}
array(6) {
  ["file_name"]=>
  string(77) "[shirt] Pokemon Master Journeys S24E01 - To Train or Not to Train! (Teletoon)"
  ["anime_season"]=>
  string(2) "24"
  ["episode_number"]=>
  string(2) "01"
  ["anime_title"]=>
  string(23) "Pokemon Master Journeys"
  ["release_group"]=>
  string(5) "shirt"
  ["episode_title"]=>
  string(25) "To Train or Not to Train!"
}
