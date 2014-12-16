<?hh //partial

use typesafety\Result;
use stdClass;

describe('Result', function() {
    beforeEach(function() {
        $message = new stdClass();
        $message->code = 2055;
        $message->descr = "error message";
        $message->path = "/foo/var/example.hh";
        $message->line = 38;
        $message->end = 26;
        $message->start = 26;

        $errorObject = new stdClass();
        $errorObject->messages = [
            $message
        ];

        $resultObject = new stdClass();
        $resultObject->passed = true;
        $resultObject->version = "817b3a0 Nov 15 2014 13:25:51";
        $resultObject->errors = [
            $error
        ];

        $this->resultObject = $resultObject;
        $this->result = Result::fromObject($resultObject);
    });
    describe('#getVersion', function() {
        it('return version text', function() {
            expect($this->result->getVersion())->toBe("817b3a0 Nov 15 2014 13:25:51");
        });
    });
    describe('#isPassed', function() {
        context('when passed', function() {
            it('return true', function() {
                expect($this->result->isPassed())->toBeTrue();
            });
        });
    });
    describe('#getErrors', function() {
        it('return Iterator<Error> instance', function() {
            expect($this->result->getErrors())->toBeAnInstanceOf(Iterator::class);
        });
    });
});
