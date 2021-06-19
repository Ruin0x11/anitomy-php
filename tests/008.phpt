--TEST--
anitomy_parse() Option: parse_release_group
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = ["parse_release_group" => false];
$ret = anitomy_parse("[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv", $options);

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
  ["success"]=>
  bool(true)
}
