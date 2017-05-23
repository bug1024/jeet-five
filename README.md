# jeet-five
A PHP extension just like npm five

## Environment
 - PHP-7.1.5

## Basic
```php
    $five = new Five();
    five->number(); // 5
```

## Multilingual
```php
    $five = new Five();
    $five->english(); // five
    $five->chinese(); // 五
    $five->chinese_pinyin(); // wǔ
    $five->chinese_financial(); // 伍
    $five->japanese(); // 五
    $five->korean(); // 오
    $five->fern(); // ❤️
    // and more
```

## Assertion
```php
    $five = new Five();
    $five->is_five(5); // true
    $five->is_five(2); // false
```

## Reference
 - [five](https://github.com/jackdcrawford/five)

## License
 - MIT

