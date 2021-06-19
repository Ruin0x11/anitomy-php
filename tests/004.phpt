--TEST--
anitomy_parse() Option: ignored_strings
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = ["ignored_strings" => ["Sub(CH,JP)", "06"]];
$ret = anitomy_parse("[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv", $options);

var_dump($ret);
?>
--EXPECT--
array(8) {
  ["file_extension"]=>
  string(3) "mkv"
  ["file_name"]=>
  string(46) "[Kamigami] Psycho-Pass -  [1280x720 x264 AAC ]"
  ["video_resolution"]=>
  string(8) "1280x720"
  ["video_term"]=>
  string(4) "x264"
  ["audio_term"]=>
  string(3) "AAC"
  ["anime_title"]=>
  string(11) "Psycho-Pass"
  ["release_group"]=>
  string(8) "Kamigami"
  ["success"]=>
  bool(true)
}
