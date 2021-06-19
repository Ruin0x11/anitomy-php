--TEST--
anitomy_parse() Option: parse_file_extension
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = ["parse_file_extension" => false];
$ret = anitomy_parse("[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv", $options);

var_dump($ret);
?>
--EXPECT--
array(9) {
  ["file_name"]=>
  string(62) "[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv"
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
  ["episode_title"]=>
  string(3) "mkv"
  ["success"]=>
  bool(true)
}
