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
$ret = anitomy_parse("[VCB-Studio] Puella Magi Madoka Magica [03][Ma10p 1080p][x265 flac]");

var_dump($ret);
?>
--EXPECT--
array(8) {
  ["file_name"]=>
  string(67) "[VCB-Studio] Puella Magi Madoka Magica [03][Ma10p 1080p][x265 flac]"
  ["video_resolution"]=>
  string(5) "1080p"
  ["video_term"]=>
  string(4) "x265"
  ["audio_term"]=>
  string(4) "flac"
  ["episode_number"]=>
  string(2) "03"
  ["anime_title"]=>
  string(25) "Puella Magi Madoka Magica"
  ["release_group"]=>
  string(10) "VCB-Studio"
  ["success"]=>
  bool(true)
}
