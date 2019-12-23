<template>
  <div>
    <div id="on" @click="switched(true)" :class="{ active : value }">On</div>
    <div id="off" @click="switched(false)" :class="{ active: !value }">Off</div>
  </div>
</template>

<script>
export default {
  props: ['value'],
  methods: {
    switched(isOn) {
      this.$emit('input', isOn)
    },
  }
}
</script>

<style scoped>
#on,
#off {
  width: 50px;
  height: 25px;
  background-color: rgb(219, 218, 218);
  padding: 2px;
  display: inline-block;
  margin: 10px -2px;
  box-sizing: content-box;
  cursor: pointer;
  text-align: center;
}

#on:hover,
#on.active {
  background-color: rgb(108, 216, 108);
}

#off:hover,
#off.active {
  background-color: rgb(218, 65, 65);
}
</style>