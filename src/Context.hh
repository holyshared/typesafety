<?hh //strict

/**
 * This file is part of hhpack\typesafety package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\typesafety;

use hhpack\typechecker\check\Result;

interface Context
{
    public function rootDirectory() : Path;
    public function isHelp() : bool;
    public function isVersion() : bool;
    public function started() : void;
    public function report(Result $result) : Awaitable<void>;
    public function finish() : void;
    public function terminated(ApplicationResult $result) : void;
}
