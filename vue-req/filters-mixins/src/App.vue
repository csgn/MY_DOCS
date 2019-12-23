<template>
  <div class="container">
    <div class="row">
      <div class="col-md-6 col-md-offset-3">
        <p> {{ message | toUpper | toLower }} </p>
      </div>
    </div>
  </div>
</template>

<script>

export default {
  data() {
    return {
      message: "HeLlO wORLd"
    }
  },
  filters: {
    toUpper(value) {
      return value.toUpperCase()
    }
  }
}
</script>

<style>
</style>
