--TEST--
anitomy_parse() Invalid options
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = [
   "allowed_delimiters" => true,
   "ignored_strings" => [1, true, ""],
   "parse_episode_number" => [],
   "parse_episode_title" => [],
   "parse_file_extension" => [],
   "parse_release_group" => []
];
$ret = anitomy_parse("[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv", $options);

var_dump($ret);
?>
--EXPECT--
array(5) {
  ["file_name"]=>
  string(62) "[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv"
  ["video_resolution"]=>
  string(8) "1280x720"
  ["video_term"]=>
  string(4) "x264"
  ["audio_term"]=>
  string(3) "AAC"
  ["anime_title"]=>
  string(16) "Psycho-Pass - 06"
}
