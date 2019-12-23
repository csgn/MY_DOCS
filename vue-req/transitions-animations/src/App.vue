<template>
  <div class="container">
    <div class="row">
      <div class="col-md-6 col-md-offset-3">
        <h3>Animation & Transition</h3><hr>
        
        <select class="form-control" v-model="activeEffect">
          <option value="fade">Fade</option>
          <option value="slide">Slide</option>
        </select>

        <button class="btn btn-dark" @click="show = !show">Show/Hide</button><br><br>

        <transition :name="activeEffect">
          <div class="alert alert-success" v-if="show">This is a Alert Box</div>
        </transition>
      
        <transition :name="activeEffect" type="animation" appear>
          <div class="alert alert-danger" v-show="!show">This is a Alert Box</div>
        </transition>

        <transition 
          enter-class=""
          enter-active-class="animated shake"
          leave-class=""
          leave-active-class="animated swing"
          appear>
          <div class="alert alert-warning" v-show="!show">This is a Alert Box</div>
        </transition>

        <br><hr>
        <transition :name="activeEffect" mode="out-in">
          <div class="alert alert-info" v-if="show" key="info">This is a Alert Box</div>
          <div class="alert alert-dark" v-else key="dark">This is a Alert Box</div>
        </transition>

        <button class="btn btn-info" @click="showJS = !showJS">Show/Hide</button><br><br>
        <transition
          :css="false"
          @before-enter="beforeEnter"
          @enter="enter"
          @after-enter="afterEnter"
          @after-enter-cancelled="afterEnterCancelled"
          @before-leave="beforeLeave"
          @leave="leave"
          @after-leave="afterLeave"
          @after-leave-cancelled="afterLeaveCancelled"
          > <div style="width: 100px; height: 100px; border: 1px black solid" v-if="showJS"> This is a Alert Box </div>
        </transition>

      </div>
    </div>
  </div>
</template>

<script>

export default {
  data() {
    return {
      show: false,
      activeEffect: 'fade',
      showJS: false,
      elementWidth: 100,
    }
  },
  methods: {
    beforeEnter(el) {
      this.elementWidth = 100
      el.style.width = this.elementWidth + "px"
    },

    enter(el, done) {
      let round = 1
      const interval = setInterval(() => {
        el.style.width = (this.elementWidth + round*10) + "px"
        round++
        if (round > 20) {
          clearInterval(interval)
          done()
        }
      }, 50)      
    },

    afterEnter(el) {
      window.console.log("afterEnter", el)

    },

    afterEnterCancelled(el) {
      window.console.log("afterEnterCancelled", el)

    },

    beforeLeave(el) {
      this.elementWidth = 300
      el.style.width = this.elementWidth + "px"
    },

    leave(el, done) {
      let round = 1
      const interval = setInterval(() => {
        el.style.width = (this.elementWidth - round*10) + "px"
        round++
        if (round > 20) {
          clearInterval(interval)
          done()
        }
      }, 50)   
    },

    afterLeave(el) {
      window.console.log("afterLeave", el)

    },

    afterLeaveCancelled(el) {
      window.console.log("afterLeaveCancelled", el)

    }
  }
}

</script>

<style>
  .fade-enter { /* ilk kare */
    opacity: 0;
  }

  .fade-enter-active {  /* DOM 'a eklenir */
    transition: opacity 1s;
  }

  .fade-leave {
    /* opacity: 1 */
  }

  .fade-leave-active {
    transition: opacity 1s;
    opacity: 0;
  }

  .slide-enter {}


  .slide-enter-active {
    animation: slide-in 1s ease-out forwards; 
  }

  .slide-leave {}

  .slide-leave-active {
    animation: slide-out 1s ease-out forwards;
    transition: opacity 1s;
    opacity: 0;
  }

  @keyframes slide-in {
    from {
      transform: translateY(20px);
    } to {
      transform: translateY(0px);
    }
  }

  @keyframes slide-out {
    from {
      transform: translateY(0px);
    } to {
      transform: translateY(20px);
    }
  }


</style>

