<?hh //partial

namespace hhpack\typesafety\spec;

use hhpack\typesafety\Arguments;
use hhpack\typesafety\ArgumentOptions;
use hhpack\typesafety\ApplicationContext;

describe(ApplicationContext::class, function() {
  describe('#isHelp', function() {
    context('when use help option', function() {
      beforeEach(function() {
        $this->context = new ApplicationContext(
          new Arguments(),
          new ArgumentOptions([ 'help' => true ])
        );
      });
      it('return true', function() {
        expect( $this->context->isHelp() )->toBeTrue();
      });
    });
    context('when not use help option', function() {
      beforeEach(function() {
        $this->context = new ApplicationContext(
          new Arguments(),
          new ArgumentOptions([ 'help' => false ])
        );
      });
      it('return false', function() {
        expect( $this->context->isHelp() )->toBeFalse();
      });
    });
  });
  describe('#isVersion', function() {
    context('when use version option', function() {
      beforeEach(function() {
        $this->context = new ApplicationContext(
          new Arguments(),
          new ArgumentOptions([ 'version' => true ])
        );
      });
      it('return true', function() {
        expect( $this->context->isVersion() )->toBeTrue();
      });
    });
    context('when not use version option', function() {
      beforeEach(function() {
        $this->context = new ApplicationContext(
          new Arguments(),
          new ArgumentOptions([ 'version' => false ])
        );
      });
      it('return false', function() {
        expect( $this->context->isVersion() )->toBeFalse();
      });
    });
  });
});
