<template>
  <div>
    <div class="memory">
     <slot name="heading"></slot>
    </div>
    <div class="memory">
      <slot name="content"></slot>
    </div>
    <div class="memory">
      <slot></slot>
    </div>
    <div class="memory">
      <slot name="author">
        <p>Buraya herhangi bir içerik gelmemiş. O yüzden default slot devreye giriyor.</p>
      </slot>
    </div>
  </div>
</template>

<script>
  export default {
      data() {
          return {
              counter: 0,
          }
      },
      destroyed() {
          window.console.log("Memory Destroyed")
      },
      activated() {
          window.console.log("Memory Activated")
      },
      deactivated() {
          window.console.log("Memory Deactivated")
      },
  }
</script>

<style scoped>
  div.memory {
    border: 1px solid #ccc;
    box-shadow: 1px 1px 2px #666;
    padding: 20px 20px;
    margin-top: 20px;
  }
</style>