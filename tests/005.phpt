--TEST--
anitomy_parse() Option: parse_episode_number
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = ["parse_episode_number" => false];
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
  ["anime_title"]=>
  string(16) "Psycho-Pass - 06"
  ["release_group"]=>
  string(8) "Kamigami"
  ["success"]=>
  bool(true)
}
