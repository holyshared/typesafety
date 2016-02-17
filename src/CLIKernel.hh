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

use hhpack\typesafety\Output;
use hhpack\typesafety\output\ConsoleOutput;

final class CLIKernel implements Kernel
{

    public function __construct
    (
        private Application $application,
        private Output $output = new ConsoleOutput()
    )
    {
    }

    public async function run(Traversable<string> $argv) : Awaitable<void>
    {
        $this->started();
        $result = await $this->application->run($argv);
        $this->finish();

        $this->terminated($result);
    }

    private function started() : void
    {
        $this->output->info('Type check started.');
    }

    private function finish() : void
    {
        $this->output->info('Type check finished.');
    }

    private function terminated(ApplicationResult $result) : void
    {
        if ($result->isError()) {
            $result->displayError($this->output);
        }
        $exitCode = $result->isOk() ? 0 : -1;
        exit($exitCode);
    }

}
