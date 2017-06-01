<?php

$five = new Five();
echo $five->number(), "\n";
echo $five->english(), "\n";
echo $five->chinese(), "\n";
echo $five->chinese("pinyin"), "\n";
echo $five->chinese("financial"), "\n";
echo $five->japanese(), "\n";
echo $five->korean(), "\n";
echo $five->fern(), "\n";
echo $five->binary(), "\n";
echo $five->is_five(5), "\n";
echo $five->is_five(4), "\n";
